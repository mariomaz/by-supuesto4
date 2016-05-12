#ifndef CLIENTTASK_H
#define CLIENTTASK_H

#include <QObject>
#include <QRunnable>
#include <QString>
#include <QTcpSocket>

#include "users.h"
#include "command.h"
#include "response.h"

class ClientTask : public QObject, public QRunnable
{
    Q_OBJECT

public:
    ClientTask(qintptr handle, QString const& name, Users* users, QObject* parent = 0);

signals:
    void requestProcessed(quint32 id, QString const& name, bool inserted);

protected:
    void run();

private:
    qintptr m_handle;
    QString m_name;
    Users* m_users;

    bool
    receiveCommand(Command* command, QTcpSocket* socket);

    bool
    sendResponse(Response* response, QTcpSocket* socket);
};

#endif // CLIENTTASK_H
