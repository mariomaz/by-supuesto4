#include "command.h"

#include <QStringList>

#define FIELD_DELIMITER ";"

Command::Command()
{
    m_id = 0;
    m_name = "";
}

quint16
Command::getId() const
{
    return m_id;
}

void
Command::setId(quint16 id)
{
    m_id = id;
}

QString
Command::getName() const
{
    return m_name;
}

void
Command::setName(QString name)
{
    m_name = name;
}

QString
Command::toString() const
{
    QString s = QString::number(m_id);
    s.append(FIELD_DELIMITER);
    s.append(m_name);

    return s;
}

bool
Command::fromString(QString const& s)
{
    bool result = false;

    QStringList tokens = s.split(FIELD_DELIMITER);
    if (tokens.length() == 2)
    {
        m_id = tokens[0].toUInt();
        m_name = tokens[1];
        result = true;
    }

    return result;
}
