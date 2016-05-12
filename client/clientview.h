#ifndef CLIENTVIEW
#define CLIENTVIEW

#include <QObject>

class ClientView : public QObject
{
    Q_OBJECT

public:

    /**
     * Class destructor.
     */
    virtual
    ~ClientView(void)
    {
    }

public slots:

    /**
     * Presenter uses these slots to update the view.
     */
    virtual void
    showCommand(quint32 id, QString const& name) = 0;

    virtual void
    showResponse(bool inserted, quint32 elapsedTime) = 0;

signals:

    /**
     * These signals are the user events sent to the presenter
     */

protected:

    /**
     * Class constructor.
     * Constructor is protected because this is a C++ interface so only derived
     * classes (i.e.: interface implementations) can use it.
     */
    explicit
    ClientView(QObject* parent = 0) : QObject(parent)
    {
    }

private:

    /**
     * Copy constructor (private and not implemented to prevent copying).
     */
    ClientView(ClientView const&);

    /**
     * Assignment operator (private and not implemented to prevent copying).
     */
    ClientView&
    operator=(ClientView const&);
};

#endif // CLIENTVIEW

