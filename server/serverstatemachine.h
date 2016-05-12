
/**
      This file was auto-generated from file:///home/user1/Workspace/Stopwatch/by/server/server.scxml by the scc compiler on 2016-05-12T15:24:57.765Z.
 */
#ifndef __SERVER_STATE_MACHINE_H
#define __SERVER_STATE_MACHINE_H

#include <QStateMachine>
#include <QSignalTransition>
#include <QEventTransition>
#include <QTimer>
#include <QMetaMethod>
#include <QPointer>
#include <QVariant>
#include <QHash>
#include <QFinalState>

#define In(state) (configuration().contains(state_##state))



#define DEFAULT_SERVER_PORT               5555
#define DEFAULT_MAX_THREAD_COUNT          10
#define DEFAULT_REPORT_FILEPATH           "/tmp/users.txt"

	

class ServerStateMachine;

#include "scc/UnconditionalTransition.h"

#include "scc/EventSender.h"

class ServerStateMachine : public QStateMachine
{
    Q_OBJECT

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
    Q_PROPERTY(quint16 port READ get_port WRITE set_port NOTIFY port_changed)

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="maxThreadCount" Qt:type="int" expr="DEFAULT_MAX_THREAD_COUNT"/>
        */
    Q_PROPERTY(int maxThreadCount READ get_maxThreadCount WRITE set_maxThreadCount NOTIFY maxThreadCount_changed)

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="reportFilepath" Qt:type="QString" expr="DEFAULT_REPORT_FILEPATH"/>
        */
    Q_PROPERTY(QString reportFilepath READ get_reportFilepath WRITE set_reportFilepath NOTIFY reportFilepath_changed)


    public:
        ServerStateMachine(QObject* o = NULL)
            : QStateMachine(o)
        {

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
            _data.port = DEFAULT_SERVER_PORT;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="maxThreadCount" Qt:type="int" expr="DEFAULT_MAX_THREAD_COUNT"/>
        */
            _data.maxThreadCount = DEFAULT_MAX_THREAD_COUNT;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="reportFilepath" Qt:type="QString" expr="DEFAULT_REPORT_FILEPATH"/>
        */
            _data.reportFilepath = DEFAULT_REPORT_FILEPATH;
    
        }
    
        /*
            <state id="server"/>
        */
        QState* state_server;
    
        /*
            <initial/>
        */
        QState* state_T15273328300;
    
        /*
            <state id="starting"/>
        */
        QState* state_starting;
    
        /*
            <state id="running"/>
        */
        QState* state_running;
    
        /*
            <state id="reporting"/>
        */
        QState* state_reporting;
    
        /*
            <state id="stopping"/>
        */
        QState* state_stopping;
    
        /*
            <state id="terminated"/>
        */
        QState* state_terminated;
    
        /*
            <final id="server_final"/>
        */
        QFinalState* state_server_final;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
        quint16 get_port() const
        {
            return _data.port;
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="maxThreadCount" Qt:type="int" expr="DEFAULT_MAX_THREAD_COUNT"/>
        */
        int get_maxThreadCount() const
        {
            return _data.maxThreadCount;
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="reportFilepath" Qt:type="QString" expr="DEFAULT_REPORT_FILEPATH"/>
        */
        QString get_reportFilepath() const
        {
            return _data.reportFilepath;
        }
    
    protected:
        struct {
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
            quint16 port;
            
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="maxThreadCount" Qt:type="int" expr="DEFAULT_MAX_THREAD_COUNT"/>
        */
            int maxThreadCount;
            
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="reportFilepath" Qt:type="QString" expr="DEFAULT_REPORT_FILEPATH"/>
        */
            QString reportFilepath;
            
        } _data;
           
        struct {
          QString name;
          QVariantList data;
        } _event;
        QString _name;
             
    public Q_SLOTS:

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
        void set_port(quint16 const & value)
        {
            _data.port = value;
            emit port_changed(value);
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="maxThreadCount" Qt:type="int" expr="DEFAULT_MAX_THREAD_COUNT"/>
        */
        void set_maxThreadCount(int const & value)
        {
            _data.maxThreadCount = value;
            emit maxThreadCount_changed(value);
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="reportFilepath" Qt:type="QString" expr="DEFAULT_REPORT_FILEPATH"/>
        */
        void set_reportFilepath(QString const & value)
        {
            _data.reportFilepath = value;
            emit reportFilepath_changed(value);
        }
    
    private Q_SLOTS:
#ifndef QT_NO_PROPERTIES
        void assignProperties()
        {
        
#endif
        }
     
        /*
            <state id="starting"/>
        */
        /*
            <onentry/>
        */
        void exec_T15273328390()
        {
            
				
        /*
            <send event="model.startServer(quint16, int)"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_model__startServer(quint16, int)")), QVariantList()<< QVariant(_data.port)
                        << QVariant(_data.maxThreadCount)
                        )
                       );

			
        }
    
        /*
            <state id="running"/>
        */
        /*
            <onentry/>
        */
        void exec_T15273328660()
        {
            
				
        /*
            <send id="timer.idle" event="timer.idle.timeout" delay="60000ms"/>
        */
                 _eventSenders["timer.idle"] = 
                       new SCC_EventSender
                       (
                             this,
                             60000,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_timer__idle__timeout()")), QVariantList())
                       );

			
        }
    
        /*
            <state id="running"/>
        */
        /*
            <onexit/>
        */
        void exec_T15273328740()
        {
            
				
        /*
            <cancel sendid="timer.idle"/>
        */
                  {
                    QPointer<SCC_EventSender> es = _eventSenders["timer.idle"];
                    if (es)
                      es->cancel();
                  }

			
        }
    
        /*
            <state id="reporting"/>
        */
        /*
            <onentry/>
        */
        void exec_T15273328930()
        {
            
				
        /*
            <send event="model.createReport(QString)"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_model__createReport(QString)")), QVariantList()<< QVariant(_data.reportFilepath)
                        )
                       );

			
        }
    
        /*
            <state id="stopping"/>
        */
        /*
            <onentry/>
        */
        void exec_T152733281160()
        {
            
				
        /*
            <send event="model.stopServer()"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_model__stopServer()")), QVariantList())
                       );

			
        }
    
   Q_SIGNALS:
        void event_model__startServer(quint16, int);
        void event_model__serverStarted();
        void event_model__serverError();
        void event_timer__idle__timeout();
        void event_model__requestProcessed(quint32, QString, bool);
        void event_model__createReport(QString);
        void event_model__reportCreated();
        void event_model__reportError();
        void event_model__stopServer();
        void event_model__serverStopped();
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
        void port_changed(quint16 const &);
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="maxThreadCount" Qt:type="int" expr="DEFAULT_MAX_THREAD_COUNT"/>
        */
        void maxThreadCount_changed(int const &);
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="reportFilepath" Qt:type="QString" expr="DEFAULT_REPORT_FILEPATH"/>
        */
        void reportFilepath_changed(QString const &);
    
    protected:
    virtual void beginSelectTransitions(QEvent *event)
    {
        if (event && !event->type() == QEvent::None) {
          switch (event->type()) {
            case QEvent::StateMachineSignal: {
              QStateMachine::SignalEvent* e = (QStateMachine::SignalEvent*)event;
              _event.data = e->arguments();
              _event.name = e->sender()->metaObject()->method(e->signalIndex()).methodSignature();
              if (e->sender() == this)
                _event.name = _event.name.mid(6);
            } break;
            default:
            break;
          }
        } else {
          _event.name = "";
          _event.data.clear();
        }
         
        assignProperties();
    }

    private:
        QHash<QString,QPointer<SCC_EventSender> > _eventSenders;

    protected:
    public:
        void setupStateMachine()
        {
            _name = "server";
            setObjectName(_name);
            
        /*
            <state id="server"/>
        */
            state_server = new QState(this);
            state_server->setObjectName("server");this->setInitialState(state_server);
            
        /*
            <initial/>
        */
            state_T15273328300 = new QState(state_server);
            state_server->setInitialState(state_T15273328300);
            
        /*
            <state id="starting"/>
        */
            state_starting = new QState(state_server);
            state_starting->setObjectName("starting");
        /*
            <state id="running"/>
        */
            state_running = new QState(state_server);
            state_running->setObjectName("running");
        /*
            <state id="reporting"/>
        */
            state_reporting = new QState(state_server);
            state_reporting->setObjectName("reporting");
        /*
            <state id="stopping"/>
        */
            state_stopping = new QState(state_server);
            state_stopping->setObjectName("stopping");
        /*
            <state id="terminated"/>
        */
            state_terminated = new QState(state_server);
            state_terminated->setObjectName("terminated");
        /*
            <final id="server_final"/>
        */
            state_server_final = new QFinalState(state_server);
            state_server_final->setObjectName("server_final");
            
            QAbstractTransition* transition;
        /*
            <transition target="starting"/>
        */
            transition = new SCC_UnconditionalTransition(state_T15273328300);
            transition->setTargetState(state_starting);
            
        /*
            <transition event="model.serverStarted" target="running"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__serverStarted()), state_starting);
            transition->setTargetState(state_running);
            
        /*
            <transition event="model.serverError" target="stopping"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__serverError()), state_starting);
            transition->setTargetState(state_stopping);
            
        /*
            <transition event="model.requestProcessed(quint32, QString, bool)" target="running"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__requestProcessed(quint32, QString, bool)), state_running);
            transition->setTargetState(state_running);
            
        /*
            <transition event="timer.idle.timeout" target="reporting"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_timer__idle__timeout()), state_running);
            transition->setTargetState(state_reporting);
            
        /*
            <transition event="model.reportCreated" target="stopping"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__reportCreated()), state_reporting);
            transition->setTargetState(state_stopping);
            
        /*
            <transition event="model.reportError" target="stopping"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__reportError()), state_reporting);
            transition->setTargetState(state_stopping);
            
        /*
            <transition event="model.serverStopped" target="terminated"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__serverStopped()), state_stopping);
            transition->setTargetState(state_terminated);
            
        /*
            <transition target="server_final"/>
        */
            transition = new SCC_UnconditionalTransition(state_terminated);
            transition->setTargetState(state_server_final);
            
            
            connect(state_starting, SIGNAL(entered()), this, SLOT(exec_T15273328390()));
            connect(state_running, SIGNAL(entered()), this, SLOT(exec_T15273328660()));
            connect(state_running, SIGNAL(exited()), this, SLOT(exec_T15273328740()));
            connect(state_reporting, SIGNAL(entered()), this, SLOT(exec_T15273328930()));
            connect(state_stopping, SIGNAL(entered()), this, SLOT(exec_T152733281160()));
        }
};
    
#endif
    
