#ifndef SERVERVIEWIMPL_H
#define SERVERVIEWIMPL_H

#include "serverview.h"

class ServerViewImpl : public ServerView
{
    Q_OBJECT

public:
    explicit
    ServerViewImpl(QObject* parent = 0);

    ~ServerViewImpl();
};

#endif // SERVERVIEWIMPL_H
