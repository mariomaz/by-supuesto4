#include "sender.h"

Sender::Sender()
{
}

bool
Sender::send(QString const& s, QTcpSocket* socket)
{
    bool result = false;

    // length-prefix framing (including \0)
    quint32 length = s.length() + 1;
    if (send(socket, (const char*) &length, sizeof(quint32)))
    {
        if (send(socket, s.toStdString().c_str(), length))
        {
            socket->flush();
            result = true;
        }
    }

    return result;
}

bool
Sender::send(QTcpSocket* socket, const char* buffer, quint32 length)
{
    qint64 bytesToWrite = length;
    qint64 bytesWritten;
    qint64 offset = 0;

    while ((bytesWritten = socket->write(&buffer[offset], bytesToWrite)) >= 0)
    {
        bytesToWrite -= bytesWritten;
        offset += bytesWritten;
        if (bytesToWrite == 0)
        {
            break;
        }
    }

    return bytesWritten >= 0;
}
