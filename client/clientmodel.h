#ifndef CLIENTMODEL_H
#define CLIENTMODEL_H

#include <QObject>
#include "command.h"
#include "response.h"

class ClientModel : public QObject
{
    Q_OBJECT

public:

    /**
     * Class destructor.
     */
    virtual
    ~ClientModel(void)
    {
    }

public slots:

    /**
     * Presenter uses these slots to update the model.
     */
    virtual bool
    connectToServer(QString const& host, quint16 port) = 0;

    virtual bool
    disconnectFromServer() = 0;

    virtual bool
    sendNextRequest() = 0;

    virtual void
    clientExit() = 0;

signals:

    /**
     * These signals are the model state-change events sent to the presenter
     */
    void connectedToServer();
    void disconnectedFromServer();
    void clientError();
    void commandSent(quint32 id, QString const& name);
    void responseReceived(bool inserted, qint64 elapsedTime);
    void terminated();

protected:

    /**
     * Class constructor.
     * Constructor is protected because this is a C++ interface so only derived
     * classes (i.e.: interface implementations) can use it.
     */
    explicit
    ClientModel(QObject* parent = 0) : QObject(parent)
    {
    }

private:

    /**
     * Copy constructor (private and not implemented to prevent copying).
     */
    ClientModel(ClientModel const&);

    /**
     * Assignment operator (private and not implemented to prevent copying).
     */
    ClientModel&
    operator=(ClientModel const&);
};

#endif // CLIENTMODEL_H

