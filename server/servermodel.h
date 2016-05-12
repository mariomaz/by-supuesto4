#ifndef SERVERMODEL
#define SERVERMODEL

#include <QObject>
#include "command.h"
#include "response.h"

class ServerModel : public QObject
{
    Q_OBJECT

public:

    /**
     * Class destructor.
     */
    virtual
    ~ServerModel(void)
    {
    }

public slots:

    /**
     * Presenter uses these slots to update the model.
     */
    virtual bool
    startServer(quint16 port, int maxThreadCount) = 0;

    virtual bool
    stopServer() = 0;

    virtual bool
    createReport(QString const& filepath) = 0;

    virtual void
    serverExit() = 0;

signals:

    /**
     * These signals are the model state-change events sent to the presenter
     */
    void serverStarted();
    void serverStopped();
    void serverError();
    void requestProcessed(quint32 id, QString const& name, bool inserted);
    void reportCreated();
    void reportError();

protected:

    /**
     * Class constructor.
     * Constructor is protected because this is a C++ interface so only derived
     * classes (i.e.: interface implementations) can use it.
     */
    explicit
    ServerModel(QObject* parent = 0) : QObject(parent)
    {
    }

private:

    /**
     * Copy constructor (private and not implemented to prevent copying).
     */
    ServerModel(ServerModel const&);

    /**
     * Assignment operator (private and not implemented to prevent copying).
     */
    ServerModel&
    operator=(ServerModel const&);
};

#endif // SERVERMODEL

