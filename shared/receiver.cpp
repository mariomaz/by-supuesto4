#include "receiver.h"

Receiver::Receiver()
{
}

QString
Receiver::receive(QTcpSocket* socket)
{
    QString s = "";
    quint32 length = 0;
    char buffer[1024];

    // length-prefix framing (including \0)
    if (receive(socket, (char*) &length, sizeof(quint32)))
    {
        if (receive(socket, buffer, length))
        {
            s = buffer;
        }
    }

    return s;
}

bool
Receiver::receive(QTcpSocket* socket, char* buffer, quint32 length)
{
    qint64 bytesToRead = length;
    qint64 bytesRead;
    qint64 offset = 0;

    while ((bytesRead = socket->read(&buffer[offset], bytesToRead)) >= 0)
    {
        bytesToRead -= bytesRead;
        offset += bytesRead;
        if (bytesToRead == 0)
        {
            break;
        }
    }

    return bytesRead >= 0;
}
