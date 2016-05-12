#include "clientviewimpl.h"

#include <iostream>

ClientViewImpl::ClientViewImpl(QObject* parent) : ClientView(parent)
{
    // REQ-3.c:
    // El cliente muestra por consola el usuario enviado, el tiempo que ha
    // tardado en recibir la respuesta y la respuesta que le ha dado el servidor.
}

ClientViewImpl::~ClientViewImpl()
{
}

void
ClientViewImpl::showCommand(quint32 id, QString const& name)
{
    std::cout << "id: " << id << ", name: " << name.toStdString() << std::endl;
}

void
ClientViewImpl::showResponse(bool inserted, quint32 elapsedTime)
{
    std::cout << "inserted: " << (inserted ? "true" : "false") << ", elapsed time: " << elapsedTime << "ms" << std::endl;
}


