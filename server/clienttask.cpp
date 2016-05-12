#include "clienttask.h"
#include "sender.h"
#include "receiver.h"

#include <QList>
#include <QDebug>

ClientTask::ClientTask(qintptr handle, QString const& name, Users* users, QObject* parent) : QObject(parent)
{
    m_handle = handle;
    m_name = name;
    m_users = users;
}

void
ClientTask::run()
{
    QTcpSocket socket;
    socket.setSocketDescriptor(m_handle);

    // El servidor asigna un nombre a cada cliente cuando se conectan
    if (Sender::send(m_name, &socket))
    {
        qDebug() << "Client " << m_name << " connected";
        while (socket.waitForReadyRead())
        {
            Command command;
            if (receiveCommand(&command, &socket))
            {
                quint16 id = command.getId();
                QString name = command.getName();

                // Sólo por si acaso ...
                if (name != m_name)
                {
                    qDebug() << "Invalid name specified '" << name << "' from client " << m_name;
                    break;
                }

                // REQ-5
                // El servidor tiene que rechazar un usuario si ya tiene
                // almacenado otro con el mismo identificador.
                bool inserted = m_users->insert(id, name);

                // REQ-6
                // El servidor devuelve un valor que indica si ha realizado o
                // no la inserción.
                Response response;
                response.setInserted(inserted);
                qDebug() << "id: " << id << ", name: " << name << ", inserted: " << (response.getInserted() ? "true" : "false");

                if (sendResponse(&response, &socket))
                {
                    emit requestProcessed(id, name, inserted);
                }
                else
                {
                    // Si el identificador ha sido insertado pero no se ha
                    // podido contestar al cliente, hay que volverlo a sacar de
                    // la lista. Ya lo insertará otro cliente
                    if (inserted)
                    {
                        m_users->remove(id);
                        qDebug() << "Unable to send response to " << m_name << ", id " << id << " removed";
                    }
                    else
                    {
                        qDebug() << "Unable to send response to " << m_name;
                    }
                    break;
                }
            }
            else
            {
                qDebug() << "Unable to get command from client " << m_name;
                break;
            }
        }
    }
    else
    {
        qDebug() << "Unable to send name to client " << m_name;
    }

    qDebug() << "Client task for " << m_name << " terminated!";
    socket.close();
}

bool
ClientTask::receiveCommand(Command* command, QTcpSocket* socket)
{
    bool result = false;

    QString s = Receiver::receive(socket);
    if (s.length() > 0)
    {
        if (command->fromString(s))
        {
            result = true;
        }
    }

    return result;
}

bool
ClientTask::sendResponse(Response* response, QTcpSocket* socket)
{
    bool result = false;

    if (Sender::send(response->toString(), socket))
    {
        result = true;
    }

    return result;
}

