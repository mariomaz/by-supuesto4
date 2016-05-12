#ifndef USERS_H
#define USERS_H

#include <QMutex>
#include <QMap>
#include <QString>

// REQ-4
// El servidor tiene que almacenar en RAM todos los usuarios que le envíen
// todos los clientes.
class Users
{
public:
    /**
     * Esta clase es el almacén en memoria de los pares identificador-nombre de
     * cliente ya enviados por los clientes.
     * @param minId Valor mínimo permitido para un identificador.
     * @param maxId Valor máximo permitido para un identificador.
     */
    Users(quint16 minId, quint16 maxId);

    /**
     * Destructor de la clase.
     */
    ~Users();

    /**
     * Inserta un nuevo par identificador-nombre de cliente en memoria.
     * El valor del identificador debe estar comprendido entre el valor mínimo
     * y máximo (ambos inclusive) especificados en el constructor.
     * @param id Identificador a insertar.
     * @param name Nombre del cliente que realiza la inserción.
     * @return Verdadero si el identificador no existía en memoria y ha sido
     * insertado y falso en caso contrario.
     */
    bool
    insert(quint16 id, QString const& name);

    /**
     * Elimina un identificador previamente insertado.
     * @param id Identificador a eliminar.
     * @return Verdadero si el identificador existía en memoria y ha sido
     * eliminado y falso en caso contrario.
     */
    bool
    remove(quint16 id);

    /**
     * Escribe en un archivo de texto la lista de usuarios recibidos con el
     * identificador del cliente que lo ha insertado.
     * @param filepath Nombre del archivo de texto.
     * @return Verdadero si el fichero se ha podido escribir y falso en caso
     * contrario.
     */
    bool
    save(QString const& filepath);

private:

    /**
     * Mutex para acceder al almacén de memoria en exclusión mútua desde
     * distintos hilos de ejecución.
     */
    QMutex m_mutex;

    /**
     * Mapa de pares identificador-nombre de cliente que da soporte al almacén.
     */
    QMap<quint16, QString> m_map;

    /**
     * Valor mínimo permitido para un identificador.
     */
    quint16 m_minId;

    /**
     * Valor máximo permitido para un identificador.
     */
    quint16 m_maxId;
};

#endif // USERS_H
