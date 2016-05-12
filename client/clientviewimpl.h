#ifndef CLIENTVIEWIMPL_H
#define CLIENTVIEWIMPL_H

#include "clientview.h"

class ClientViewImpl : public ClientView
{
    Q_OBJECT

public:

    explicit
    ClientViewImpl(QObject* parent = 0);

    ~ClientViewImpl();

public slots:

    /**
     * Presenter uses these slots to update the view.
     */
    virtual void
    showCommand(quint32 id, QString const& name);

    virtual void
    showResponse(bool inserted, quint32 elapsedTime);
};

#endif // CLIENTVIEWIMPL_H
