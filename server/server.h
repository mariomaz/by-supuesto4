#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit
    Server(QObject* parent = 0);

    ~Server();

signals:
    void clientConnected(qintptr handle);

protected:
    void incomingConnection(qintptr handle);
};

#endif // SERVER_H
