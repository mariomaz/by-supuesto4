#include "server.h"

#include <QDebug>

Server::Server(QObject* parent) : QTcpServer(parent)
{
}

Server::~Server()
{
}

void
Server::incomingConnection(qintptr handle)
{
    emit clientConnected(handle);
}
