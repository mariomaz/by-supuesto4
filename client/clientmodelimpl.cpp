#include "clientmodelimpl.h"

#include <QDebug>
#include <QTime>
#include <QElapsedTimer>

#include "sender.h"
#include "receiver.h"

ClientModelImpl::ClientModelImpl(QObject* parent) : ClientModel(parent)
{
    m_name = "";
    m_socket = 0;

    // REQ-3.b
    // El identificador es un valor aleatorio entre 1 y 250 y que no
    // se repite en cada ejecución
    for (quint16 i = MIN_COMMAND_ID; i <= MAX_COMMAND_ID; i++)
    {
        m_list.append(i);
    }

    // Seed the random number generator.
    qsrand(QTime::currentTime().msec());
}

ClientModelImpl::~ClientModelImpl()
{
}

bool
ClientModelImpl::connectToServer(QString const& host, quint16 port)
{
    bool result = false;

    if (0 == m_socket)
    {
        m_socket = new QTcpSocket(this);
        connect(m_socket, SIGNAL(connected()), this, SLOT(connected()));
        connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
        connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));

        m_socket->connectToHost(host, port);
        result = true;
    }

    return result;
}

bool
ClientModelImpl::disconnectFromServer()
{
    bool result = false;

    if (m_socket)
    {
        m_socket->disconnectFromHost();
        result = true;
    }

    return result;
}

bool
ClientModelImpl::sendNextRequest()
{
    bool result = false;

    if (m_socket)
    {
        // REQ-3.a
        // El cliente envía cada segundo peticiones de inserción de un Usuario
        // con los datos: Id y Name.
        Command command;
        command.setId(getRandomId());
        command.setName(m_name);

        QElapsedTimer stopwatch;
        stopwatch.start();

        if (sendCommand(&command))
        {
            emit commandSent(command.getId(), command.getName());

            Response response;
            if (recvResponse(&response))
            {
                // REQ-3.c
                // El cliente muestra por consola el usuario enviado, el tiempo
                // que ha tardado en recibir la respuesta y la respuesta que le
                // ha dado el servidor
                qint64 elapsedTime = stopwatch.elapsed();
                emit responseReceived(response.getInserted(), elapsedTime);

                // REQ-7
                // La ejecución del cliente termina cuando no tiene más
                // identificadores libres
                if (m_list.length() == 0)
                {
                    emit terminated();
                }
                result = true;
            }
            else
            {
                emit clientError();
            }
        }
        else
        {
            emit clientError();
        }
    }

    return result;
}

void
ClientModelImpl::clientExit()
{
    exit(0);
}

quint16
ClientModelImpl::getRandomId()
{
    int index = qrand() % m_list.length();
    quint16 id = m_list[index];
    m_list.removeAt(index);

    return id;
}

bool
ClientModelImpl::sendCommand(Command* command)
{
    bool result = false;

    if (m_socket)
    {
        if (Sender::send(command->toString(), m_socket))
        {
            result = true;
        }
    }

    return result;
}

bool
ClientModelImpl::recvResponse(Response* response)
{
    bool result = false;

    if (m_socket)
    {
        if (m_socket->waitForReadyRead())
        {
            QString s = Receiver::receive(m_socket);
            if (s.length() > 0)
            {
                result = response->fromString(s);
            }
        }
    }

    return result;
}

void
ClientModelImpl::connected()
{
    // REQ-2
    // El servidor asigna un nombre a cada cliente cuando se conectan
    if (m_socket->waitForReadyRead())
    {
        m_name = Receiver::receive(m_socket);
        if (m_name > 0)
        {
            qDebug() << "name: " << m_name;
            emit connectedToServer();
        }
        else
        {
            qDebug() << "Unable to get client name";
            m_socket->disconnectFromHost();
            emit clientError();
        }
    }
}

void
ClientModelImpl::disconnected()
{
    delete m_socket;
    m_socket = 0;
    emit disconnectedFromServer();
}

void
ClientModelImpl::error(QAbstractSocket::SocketError socketError)
{
    qDebug() << "error event: " << socketError;
    m_socket->close();
    emit clientError();
}
