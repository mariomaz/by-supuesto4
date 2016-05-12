#include "servermodelimpl.h"
#include "clienttask.h"

#include <QDebug>

ServerModelImpl::ServerModelImpl(QObject* parent) : ServerModel(parent)
{
    m_server = 0;
    m_threadPool = new QThreadPool((QTcpServer*) this);
    m_users = new Users(MIN_COMMAND_ID, MAX_COMMAND_ID);
}

ServerModelImpl::~ServerModelImpl()
{
    delete m_threadPool;
    delete m_users;
}

bool
ServerModelImpl::startServer(quint16 port, int maxThreadCount)
{
    bool result = false;

    if (0 == m_server)
    {
        m_threadPool->setMaxThreadCount(maxThreadCount);

        m_server = new Server();
        connect(m_server, SIGNAL(clientConnected(qintptr)), this, SLOT(clientConnected(qintptr)));

        if (m_server->listen(QHostAddress::Any, port))
        {
            emit serverStarted();
            result = true;
        }
        else
        {
            emit serverError();
        }
    }

    return result;
}

bool
ServerModelImpl::stopServer()
{
    bool result = false;

    if (m_server)
    {
        m_server->close();
        emit serverStopped();
        result = true;
    }

    return result;
}

bool
ServerModelImpl::createReport(QString const& filepath)
{
    bool result = false;

    // REQ-8.b
    // Antes de finalizar escribe en un archivo de texto la lista de usuarios
    // recibidos con el identificador del cliente que lo ha insertado
    if (m_users->save(filepath))
    {
        emit reportCreated();
        result = true;
    }
    else
    {
        emit reportError();
    }

    return result;
}


void
ServerModelImpl::serverExit()
{
    exit(0);
}

void
ServerModelImpl::clientConnected(qintptr handle)
{
    // REQ-2:
    // El servidor asigna un nombre a cada cliente cuando se conectan
    QString clientName = getNextClientName();

    ClientTask *task = new ClientTask(handle, clientName, m_users);
    task->setAutoDelete(true);

    connect(task, SIGNAL(requestProcessed(quint32, QString, bool)), this, SLOT(commandProcessed(quint32, QString, bool)));

    m_threadPool->start(task);
}

void
ServerModelImpl::commandProcessed(quint32 id, QString const& name, bool inserted)
{
    // REQ-8.a
    // La ejecución del servidor termina cuando hace más de 1 minuto que ningún
    // cliente le ha realizado ninguna petición.
    emit requestProcessed(id, name, inserted);
}

QString
ServerModelImpl::getNextClientName()
{
    // REQ-2
    // El servidor asigna un nombre a cada cliente cuando se conectan
    static quint32 count = 0;

    QString name = "Client #";
    name.append(QString::number(count));
    count++;

    return name;
}

