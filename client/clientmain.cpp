#include <QCoreApplication>

#include "clientmodelimpl.h"
#include "clientviewimpl.h"
#include "clientstatemachine.h"

int main(int argc, char *argv[])
{
    // REQ-1:
    // Ambas aplicaciones son de aplicaciones de consola
    QCoreApplication a(argc, argv);

    ClientModelImpl model;
    ClientViewImpl view;
    ClientStateMachine presenter;

    presenter.setupStateMachine();

    QObject::connect(&model, SIGNAL(connectedToServer()), &presenter, SIGNAL(event_model__connectedToServer()));
    QObject::connect(&model, SIGNAL(disconnectedFromServer()), &presenter, SIGNAL(event_model__disconnectedFromServer()));
    QObject::connect(&model, SIGNAL(clientError()), &presenter, SIGNAL(event_model__clientError()));
    QObject::connect(&model, SIGNAL(commandSent(quint32, QString)), &presenter, SIGNAL(event_model__commandSent(quint32, QString)));
    QObject::connect(&model, SIGNAL(responseReceived(bool,qint64)), &presenter, SIGNAL(event_model__responseReceived(bool,qint64)));
    QObject::connect(&model, SIGNAL(terminated()), &presenter, SIGNAL(event_model__terminated()));

    QObject::connect(&presenter, SIGNAL(event_view__showCommand(quint32, QString)), &view, SLOT(showCommand(quint32,QString)));
    QObject::connect(&presenter, SIGNAL(event_view__showResponse(bool, quint32)), &view, SLOT(showResponse(bool,quint32)));

    QObject::connect(&presenter, SIGNAL(event_model__connectToServer(QString, quint16)), &model, SLOT(connectToServer(QString, quint16)));
    QObject::connect(&presenter, SIGNAL(event_model__disconnectFromServer()), &model, SLOT(disconnectFromServer()));
    QObject::connect(&presenter, SIGNAL(event_model__sendNextRequest()), &model, SLOT(sendNextRequest()));

    QObject::connect(presenter.state_client_final, SIGNAL(entered()), &model, SLOT(clientExit()));

    presenter.start();

    return a.exec();
}
