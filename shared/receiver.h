#ifndef RECEIVER_H
#define RECEIVER_H

#include <QTcpSocket>

class Receiver
{
public:

    static QString
    receive(QTcpSocket* socket);

protected:
    static bool
    receive(QTcpSocket* socket, char* buffer, quint32 length);

private:
    /**
     * Class constructor.
     * Constructor is private because all methods are static
     */
    Receiver();
};

#endif // RECEIVER_H
