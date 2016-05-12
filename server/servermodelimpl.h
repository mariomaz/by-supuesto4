#ifndef SERVERMODELIMPL_H
#define SERVERMODELIMPL_H

#include "servermodel.h"
#include "server.h"
#include "users.h"

#include <QObject>
#include <QThreadPool>

class ServerModelImpl : public ServerModel
{
    Q_OBJECT

public:
    explicit
    ServerModelImpl(QObject* parent = 0);

    ~ServerModelImpl();

public slots:

    /**
     * Presenter uses these slots to update the model.
     */
    virtual bool
    startServer(quint16 port, int maxThreadCount);

    virtual bool
    stopServer();

    virtual bool
    createReport(QString const& filepath);

    virtual void
    serverExit();

protected:

    /**
     * Servidor socket TCP
     */
    Server *m_server;

    /**
     * Pool de threads con los que procesar las conexiones de los clientes.
     * Por cada conexión se crea una tarea y se añade al pool para gestionar
     * esa conexión en un hilo diferente, ejecutado en paralelo con los demás.
     */
    QThreadPool *m_threadPool;

    /**
     * Almacén en memoria de los pares identificador-nombre del cliente.
     */
    Users *m_users;

    /**
     * Obtiene el siguiente nombre a asignar a un cliente recién conectado.
     * @return Nombre único del cliente.
     */
    QString
    getNextClientName();

private slots:

    void clientConnected(qintptr handle);
    void commandProcessed(quint32 id, QString const& name, bool inserted);
};

#endif // SERVERMODELIMPL_H
