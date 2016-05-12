#ifndef COMMAND_H
#define COMMAND_H

#include <QString>

#define MAX_COMMAND_ID 250
#define MIN_COMMAND_ID 1

class Command
{
public:
    Command();

    quint16
    getId() const;

    void
    setId(quint16 id);

    QString
    getName() const;

    void
    setName(QString name);

    QString
    toString() const;

    bool
    fromString(QString const& s);

protected:
    quint16 m_id;
    QString m_name;
};

#endif // COMMAND_H
