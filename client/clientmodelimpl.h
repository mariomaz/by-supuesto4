#ifndef CLIENTMODELIMPL_H
#define CLIENTMODELIMPL_H

#include "clientmodel.h"

#include <QTcpSocket>
#include <QThreadPool>
#include <QList>

class ClientModelImpl : public ClientModel
{
    Q_OBJECT

public:

    explicit
    ClientModelImpl(QObject* parent = 0);

    ~ClientModelImpl();

public slots:

    /**
     * Presenter uses these slots to update the model.
     */
    virtual bool
    connectToServer(QString const& host, quint16 port);

    virtual bool
    disconnectFromServer();

    virtual bool
    sendNextRequest();

    virtual void
    clientExit();

protected:

    /**
     * Nombre de cliente asignado por el servidor
     */
    QString m_name;

    /**
     * Lista con los identificadores a enviar al servidor.
     * Esta lista se inicializa con los valores del 1 al 250.
     * Cada segundo se saca un identificador de la lista de forma aleatoria y
     * se envía al servidor.
     */
    QList<quint16> m_list;

    /**
     * Socket TCP cliente con el que se establece la conexión con el servidor.
     */
    QTcpSocket *m_socket;

    /**
     * Obtiene el siguiente identificador de la lista de forma aleatoria y lo
     * saca de la lista.
     * @return identificador aleatorio
     */
    quint16
    getRandomId();

    /**
     * Envía el comando especificado al servidor por la conexión establecida a
     * través del socket.
     * @param command Comando a enviar.
     * @return Verdadero si el comando se ha podido enviar y falso en caso
     * contrario
     */
    bool
    sendCommand(Command* command);

    /**
     * Recibe la respuesta del servidor al comando enviado previamente por de la
     * conexión establecida a través del socket.
     * @param response Respuesta a recibir.
     * @return Verdadero si la respuesta se ha podido recibir y falso en caso
     * contrario
     */
    bool
    recvResponse(Response* response);

private slots:

    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
};

#endif // CLIENTMODELIMPL_H
