#include "users.h"

#include <QFile>
#include <QTextStream>

Users::Users(quint16 minId, quint16 maxId)
{
    m_minId = minId;
    m_maxId = maxId;
}

Users::~Users()
{
}

bool
Users::insert(quint16 id, QString const& name)
{
    bool result = false;
    QMutexLocker locker(&m_mutex);

    if ((id >= m_minId) && (id <= m_maxId))
    {
        if (!m_map.contains(id))
        {
            m_map.insert(id, name);
            result = true;
        }
    }

    return result;
}

bool
Users::remove(quint16 id)
{
    QMutexLocker locker(&m_mutex);
    return m_map.remove(id) > 0;
}

bool
Users::save(QString const& filepath)
{
    bool result = false;

    QMutexLocker locker(&m_mutex);

    QFile file(filepath);
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);

        QMapIterator<quint16, QString> i(m_map);
        while (i.hasNext()) {
            i.next();
            stream << i.key() << ": " << i.value() << endl;
        }

        file.close();

        result = true;
    }

    return result;
}
