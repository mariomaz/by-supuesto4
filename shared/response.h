#ifndef RESPONSE_H
#define RESPONSE_H

#include <QString>

class Response
{
public:
    Response();

    bool
    getInserted() const;

    void
    setInserted(bool inserted);

    QString
    toString() const;

    bool
    fromString(QString const& s);

protected:
    bool m_inserted;
};

#endif // RESPONSE_H
