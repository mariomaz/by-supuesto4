#ifndef SENDER_H
#define SENDER_H

#include <QTcpSocket>

class Sender
{
public:

    static bool
    send(QString const& s, QTcpSocket* socket);

protected:
    static bool
    send(QTcpSocket* socket, const char* buffer, quint32 length);

private:
    /**
     * Class constructor.
     * Constructor is private because all methods are static
     */
    Sender();
};

#endif // SENDER_H
