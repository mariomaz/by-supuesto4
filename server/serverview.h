#ifndef SERVERVIEW
#define SERVERVIEW

#include <QObject>

class ServerView : public QObject
{
    Q_OBJECT

public:

    /**
     * Class destructor.
     */
    virtual
    ~ServerView(void)
    {
    }

public slots:

    /**
     * Presenter uses these slots to update the view.
     */

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
    ServerView(QObject* parent = 0) : QObject(parent)
    {
    }

private:

    /**
     * Copy constructor (private and not implemented to prevent copying).
     */
    ServerView(ServerView const&);

    /**
     * Assignment operator (private and not implemented to prevent copying).
     */
    ServerView&
    operator=(ServerView const&);
};

#endif // SERVERVIEW

