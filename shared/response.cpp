#include "response.h"

Response::Response()
{
    m_inserted = false;
}

bool
Response::getInserted() const
{
    return m_inserted;
}

void
Response::setInserted(bool inserted)
{
    m_inserted = inserted;
}

QString
Response::toString() const
{
    return m_inserted ? "true" : "false";
}

bool
Response::fromString(QString const& s)
{
    bool result = true;

    if (s == "true")
    {
        m_inserted = true;
    }
    else if (s == "false")
    {
        m_inserted = false;
    }
    else
    {
        result = false;
    }

    return result;
}
