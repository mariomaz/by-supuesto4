#include <QCoreApplication>

#include "servermodelimpl.h"
#include "serverviewimpl.h"
#include "serverstatemachine.h"

int main(int argc, char *argv[])
{
    // REQ-1:
    // Ambas aplicaciones son de aplicaciones de consola
    QCoreApplication a(argc, argv);

    ServerModelImpl model;
    ServerViewImpl view;
    ServerStateMachine presenter;

    presenter.setupStateMachine();

    QObject::connect(&model, SIGNAL(serverStarted()), &presenter, SIGNAL(event_model__serverStarted()));
    QObject::connect(&model, SIGNAL(serverStopped()), &presenter, SIGNAL(event_model__serverStopped()));
    QObject::connect(&model, SIGNAL(serverError()), &presenter, SIGNAL(event_model__serverError()));
    QObject::connect(&model, SIGNAL(requestProcessed(quint32, QString, bool)), &presenter, SIGNAL(event_model__requestProcessed(quint32, QString, bool)));
    QObject::connect(&model, SIGNAL(reportCreated()), &presenter, SIGNAL(event_model__reportCreated()));
    QObject::connect(&model, SIGNAL(reportError()), &presenter, SIGNAL(event_model__reportError()));

    QObject::connect(&presenter, SIGNAL(event_model__startServer(quint16, int)), &model, SLOT(startServer(quint16, int)));
    QObject::connect(&presenter, SIGNAL(event_model__stopServer()), &model, SLOT(stopServer()));
    QObject::connect(&presenter, SIGNAL(event_model__createReport(QString)), &model, SLOT(createReport(QString)));

    QObject::connect(presenter.state_server_final, SIGNAL(entered()), &model, SLOT(serverExit()));

    presenter.start();


    return a.exec();
}
