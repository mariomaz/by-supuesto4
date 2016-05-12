
/**
      This file was auto-generated from file:///home/user1/Workspace/Stopwatch/by/client/client.scxml by the scc compiler on 2016-05-12T15:25:21.123Z.
 */
#ifndef __CLIENT_STATE_MACHINE_H
#define __CLIENT_STATE_MACHINE_H

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


#include <QElapsedTimer>

#define DEFAULT_SERVER_HOST               "127.0.0.1"
#define DEFAULT_SERVER_PORT               5555

	

class ClientStateMachine;

#include "scc/UnconditionalTransition.h"

#include "scc/EventSender.h"

class ClientStateMachine : public QStateMachine
{
    Q_OBJECT

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="host" Qt:type="QString" expr="DEFAULT_SERVER_HOST"/>
        */
    Q_PROPERTY(QString host READ get_host WRITE set_host NOTIFY host_changed)

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
    Q_PROPERTY(quint16 port READ get_port WRITE set_port NOTIFY port_changed)

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="id" Qt:type="quint32" expr="0"/>
        */
    Q_PROPERTY(quint32 id READ get_id WRITE set_id NOTIFY id_changed)

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="name" Qt:type="QString" expr=""/>
        */
    Q_PROPERTY(QString name READ get_name WRITE set_name NOTIFY name_changed)

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="inserted" Qt:type="bool" expr="false"/>
        */
    Q_PROPERTY(bool inserted READ get_inserted WRITE set_inserted NOTIFY inserted_changed)

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="elapsedTime" Qt:type="quint32" expr="0"/>
        */
    Q_PROPERTY(quint32 elapsedTime READ get_elapsedTime WRITE set_elapsedTime NOTIFY elapsedTime_changed)


    public:
        ClientStateMachine(QObject* o = NULL)
            : QStateMachine(o)
        {

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="host" Qt:type="QString" expr="DEFAULT_SERVER_HOST"/>
        */
            _data.host = DEFAULT_SERVER_HOST;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
            _data.port = DEFAULT_SERVER_PORT;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="id" Qt:type="quint32" expr="0"/>
        */
            _data.id = 0;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="inserted" Qt:type="bool" expr="false"/>
        */
            _data.inserted = false;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="elapsedTime" Qt:type="quint32" expr="0"/>
        */
            _data.elapsedTime = 0;
    
        }
    
        /*
            <state id="client"/>
        */
        QState* state_client;
    
        /*
            <initial/>
        */
        QState* state_T30657904450;
    
        /*
            <state id="connecting"/>
        */
        QState* state_connecting;
    
        /*
            <state id="connected"/>
        */
        QState* state_connected;
    
        /*
            <initial/>
        */
        QState* state_T30657904810;
    
        /*
            <state id="idle"/>
        */
        QState* state_idle;
    
        /*
            <state id="running"/>
        */
        QState* state_running;
    
        /*
            <initial/>
        */
        QState* state_T306579041160;
    
        /*
            <state id="sending"/>
        */
        QState* state_sending;
    
        /*
            <state id="waiting"/>
        */
        QState* state_waiting;
    
        /*
            <state id="disconnecting"/>
        */
        QState* state_disconnecting;
    
        /*
            <state id="disconnected"/>
        */
        QState* state_disconnected;
    
        /*
            <final id="client_final"/>
        */
        QFinalState* state_client_final;
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="host" Qt:type="QString" expr="DEFAULT_SERVER_HOST"/>
        */
        QString get_host() const
        {
            return _data.host;
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
        quint16 get_port() const
        {
            return _data.port;
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="id" Qt:type="quint32" expr="0"/>
        */
        quint32 get_id() const
        {
            return _data.id;
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="name" Qt:type="QString" expr=""/>
        */
        QString get_name() const
        {
            return _data.name;
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="inserted" Qt:type="bool" expr="false"/>
        */
        bool get_inserted() const
        {
            return _data.inserted;
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="elapsedTime" Qt:type="quint32" expr="0"/>
        */
        quint32 get_elapsedTime() const
        {
            return _data.elapsedTime;
        }
    
    protected:
        struct {
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="host" Qt:type="QString" expr="DEFAULT_SERVER_HOST"/>
        */
            QString host;
            
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
            quint16 port;
            
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="id" Qt:type="quint32" expr="0"/>
        */
            quint32 id;
            
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="name" Qt:type="QString" expr=""/>
        */
            QString name;
            
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="inserted" Qt:type="bool" expr="false"/>
        */
            bool inserted;
            
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="elapsedTime" Qt:type="quint32" expr="0"/>
        */
            quint32 elapsedTime;
            
        } _data;
           
        struct {
          QString name;
          QVariantList data;
        } _event;
        QString _name;
             
    public Q_SLOTS:

        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="host" Qt:type="QString" expr="DEFAULT_SERVER_HOST"/>
        */
        void set_host(QString const & value)
        {
            _data.host = value;
            emit host_changed(value);
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
        void set_port(quint16 const & value)
        {
            _data.port = value;
            emit port_changed(value);
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="id" Qt:type="quint32" expr="0"/>
        */
        void set_id(quint32 const & value)
        {
            _data.id = value;
            emit id_changed(value);
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="name" Qt:type="QString" expr=""/>
        */
        void set_name(QString const & value)
        {
            _data.name = value;
            emit name_changed(value);
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="inserted" Qt:type="bool" expr="false"/>
        */
        void set_inserted(bool const & value)
        {
            _data.inserted = value;
            emit inserted_changed(value);
        }
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="elapsedTime" Qt:type="quint32" expr="0"/>
        */
        void set_elapsedTime(quint32 const & value)
        {
            _data.elapsedTime = value;
            emit elapsedTime_changed(value);
        }
    
    private Q_SLOTS:
#ifndef QT_NO_PROPERTIES
        void assignProperties()
        {
        
#endif
        }
     
        /*
            <state id="connecting"/>
        */
        /*
            <onentry/>
        */
        void exec_T30657904540()
        {
            
				
        /*
            <send event="model.connectToServer(QString, quint16)"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_model__connectToServer(QString, quint16)")), QVariantList()<< QVariant(_data.host)
                        << QVariant(_data.port)
                        )
                       );

			
        }
    
        /*
            <state id="idle"/>
        */
        /*
            <onentry/>
        */
        void exec_T30657904900()
        {
            
					
        /*
            <send id="timer.run" event="timer.run.timeout" delay="1000ms"/>
        */
                 _eventSenders["timer.run"] = 
                       new SCC_EventSender
                       (
                             this,
                             1000,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_timer__run__timeout()")), QVariantList())
                       );

				
        }
    
        /*
            <state id="idle"/>
        */
        /*
            <onexit/>
        */
        void exec_T30657904980()
        {
            
					
        /*
            <cancel sendid="timer.run"/>
        */
                  {
                    QPointer<SCC_EventSender> es = _eventSenders["timer.run"];
                    if (es)
                      es->cancel();
                  }

				
        }
    
        /*
            <state id="sending"/>
        */
        /*
            <onentry/>
        */
        void exec_T306579041250()
        {
            
						
        /*
            <send event="model.sendNextRequest()"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_model__sendNextRequest()")), QVariantList())
                       );

					
        }
    
        /*
            <state id="sending"/>
        */
        /*
            <transition event="model.commandSent(quint32, QString)" target="waiting"/>
        */
        void exec_T306579041310()
        {
            
						
        /*
            <assign location="_data.id" expr="_event.data[0].toUInt()"/>
        */                _data.id = (_event.data[0].toUInt());

						
        /*
            <assign location="_data.name" expr="_event.data[1].toString()"/>
        */                _data.name = (_event.data[1].toString());

						
        /*
            <send event="view.showCommand(quint32, QString)"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_view__showCommand(quint32, QString)")), QVariantList()<< QVariant(_data.id)
                        << QVariant(_data.name)
                        )
                       );

					
        }
    
        /*
            <state id="waiting"/>
        */
        /*
            <transition event="model.responseReceived(bool, qint64)" target="idle"/>
        */
        void exec_T306579041600()
        {
            
						
        /*
            <assign location="_data.inserted" expr="_event.data[0].toBool()"/>
        */                _data.inserted = (_event.data[0].toBool());

						
        /*
            <assign location="_data.elapsedTime" expr="_event.data[1].toUInt()"/>
        */                _data.elapsedTime = (_event.data[1].toUInt());

						
        /*
            <send event="view.showResponse(bool, quint32)"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_view__showResponse(bool, quint32)")), QVariantList()<< QVariant(_data.inserted)
                        << QVariant(_data.elapsedTime)
                        )
                       );

					
        }
    
        /*
            <state id="disconnecting"/>
        */
        /*
            <onentry/>
        */
        void exec_T306579041940()
        {
            
					
        /*
            <send event="model.disconnectFromServer()"/>
        */
                       new SCC_EventSender
                       (
                             this,
                             0,
                            
                             new QStateMachine::SignalEvent(this,metaObject()->indexOfSignal(QMetaObject::normalizedSignature("event_model__disconnectFromServer()")), QVariantList())
                       );

				
        }
    
   Q_SIGNALS:
        void event_model__connectToServer(QString, quint16);
        void event_model__connectedToServer();
        void event_model__clientError();
        void event_timer__run__timeout();
        void event_model__terminated();
        void event_model__sendNextRequest();
        void event_model__commandSent(quint32, QString);
        void event_view__showCommand(quint32, QString);
        void event_model__responseReceived(bool, qint64);
        void event_view__showResponse(bool, quint32);
        void event_model__disconnectFromServer();
        void event_model__disconnectedFromServer();
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="host" Qt:type="QString" expr="DEFAULT_SERVER_HOST"/>
        */
        void host_changed(QString const &);
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="port" Qt:type="quint16" expr="DEFAULT_SERVER_PORT"/>
        */
        void port_changed(quint16 const &);
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="id" Qt:type="quint32" expr="0"/>
        */
        void id_changed(quint32 const &);
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="name" Qt:type="QString" expr=""/>
        */
        void name_changed(QString const &);
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="inserted" Qt:type="bool" expr="false"/>
        */
        void inserted_changed(bool const &);
    
        /*
            <data xmlns:Qt="http://www.qtsoftware.com scxml-ext" id="elapsedTime" Qt:type="quint32" expr="0"/>
        */
        void elapsedTime_changed(quint32 const &);
    
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
            _name = "client";
            setObjectName(_name);
            
        /*
            <state id="client"/>
        */
            state_client = new QState(this);
            state_client->setObjectName("client");this->setInitialState(state_client);
            
        /*
            <initial/>
        */
            state_T30657904450 = new QState(state_client);
            state_client->setInitialState(state_T30657904450);
            
        /*
            <state id="connecting"/>
        */
            state_connecting = new QState(state_client);
            state_connecting->setObjectName("connecting");
        /*
            <state id="connected"/>
        */
            state_connected = new QState(state_client);
            state_connected->setObjectName("connected");
        /*
            <initial/>
        */
            state_T30657904810 = new QState(state_connected);
            state_connected->setInitialState(state_T30657904810);
            
        /*
            <state id="idle"/>
        */
            state_idle = new QState(state_connected);
            state_idle->setObjectName("idle");
        /*
            <state id="running"/>
        */
            state_running = new QState(state_connected);
            state_running->setObjectName("running");
        /*
            <initial/>
        */
            state_T306579041160 = new QState(state_running);
            state_running->setInitialState(state_T306579041160);
            
        /*
            <state id="sending"/>
        */
            state_sending = new QState(state_running);
            state_sending->setObjectName("sending");
        /*
            <state id="waiting"/>
        */
            state_waiting = new QState(state_running);
            state_waiting->setObjectName("waiting");
        /*
            <state id="disconnecting"/>
        */
            state_disconnecting = new QState(state_connected);
            state_disconnecting->setObjectName("disconnecting");
        /*
            <state id="disconnected"/>
        */
            state_disconnected = new QState(state_connected);
            state_disconnected->setObjectName("disconnected");
        /*
            <final id="client_final"/>
        */
            state_client_final = new QFinalState(state_connected);
            state_client_final->setObjectName("client_final");
            
            QAbstractTransition* transition;
        /*
            <transition target="connecting"/>
        */
            transition = new SCC_UnconditionalTransition(state_T30657904450);
            transition->setTargetState(state_connecting);
            
        /*
            <transition event="model.connectedToServer" target="connected"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__connectedToServer()), state_connecting);
            transition->setTargetState(state_connected);
            
        /*
            <transition event="model.clientError()" target="client_final"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__clientError()), state_connecting);
            transition->setTargetState(state_client_final);
            
        /*
            <transition target="idle"/>
        */
            transition = new SCC_UnconditionalTransition(state_T30657904810);
            transition->setTargetState(state_idle);
            
        /*
            <transition event="timer.run.timeout" target="running"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_timer__run__timeout()), state_idle);
            transition->setTargetState(state_running);
            
        /*
            <transition event="model.terminated" target="disconnecting"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__terminated()), state_idle);
            transition->setTargetState(state_disconnecting);
            
        /*
            <transition target="sending"/>
        */
            transition = new SCC_UnconditionalTransition(state_T306579041160);
            transition->setTargetState(state_sending);
            
        /*
            <transition event="model.commandSent(quint32, QString)" target="waiting"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__commandSent(quint32, QString)), state_sending);
            connect(transition,SIGNAL(triggered()), this, SLOT(exec_T306579041310()));
            transition->setTargetState(state_waiting);
            
        /*
            <transition event="model.responseReceived(bool, qint64)" target="idle"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__responseReceived(bool, qint64)), state_waiting);
            connect(transition,SIGNAL(triggered()), this, SLOT(exec_T306579041600()));
            transition->setTargetState(state_idle);
            
        /*
            <transition event="model.clientError()" target="disconnecting"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__clientError()), state_running);
            transition->setTargetState(state_disconnecting);
            
        /*
            <transition event="model.disconnectedFromServer" target="disconnected"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__disconnectedFromServer()), state_disconnecting);
            transition->setTargetState(state_disconnected);
            
        /*
            <transition event="model.clientError()" target="client_final"/>
        */
            transition = new QSignalTransition(this, SIGNAL(event_model__clientError()), state_disconnecting);
            transition->setTargetState(state_client_final);
            
        /*
            <transition target="client_final"/>
        */
            transition = new SCC_UnconditionalTransition(state_disconnected);
            transition->setTargetState(state_client_final);
            
            
            connect(state_connecting, SIGNAL(entered()), this, SLOT(exec_T30657904540()));
            connect(state_idle, SIGNAL(entered()), this, SLOT(exec_T30657904900()));
            connect(state_idle, SIGNAL(exited()), this, SLOT(exec_T30657904980()));
            connect(state_sending, SIGNAL(entered()), this, SLOT(exec_T306579041250()));
            connect(state_disconnecting, SIGNAL(entered()), this, SLOT(exec_T306579041940()));
        }
};
    
#endif
    
