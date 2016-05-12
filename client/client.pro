#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T11:26:17
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    clientmodelimpl.cpp \
    clientviewimpl.cpp \
    clientmain.cpp

HEADERS += \
    clientmodel.h \
    clientmodelimpl.h \
    clientview.h \
    clientviewimpl.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../output/release/ -lshared
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../output/debug/ -lshared
else:unix: LIBS += -L$$PWD/../output/ -lshared

INCLUDEPATH += $$PWD/../shared
DEPENDPATH += $$PWD/../shared

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../output/release/libshared.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../output/debug/libshared.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../output/release/shared.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../output/debug/shared.lib
else:unix: PRE_TARGETDEPS += $$PWD/../output/libshared.a

#
# State machine
#
# The Qt statechart compiler (scc) takes an SCXML file, and using the XSLT
# feature in xmlpatterns, translates it into a header file that can be used
# in your application.
# The generated header file is a simple subclass of QStateMachine, with
# signals to represent SCXML events, properties to represent SCXML data
# elements, and a setupStateMachine() function to initialize
STATECHART = client.scxml
STATEMACHINE = clientstatemachine.h

OTHER_FILES += \
    $$STATECHART

# This is the way Qt says "scc" should be invoked
# https://blog.qt.io/blog/2009/08/10/introducing-scc-the-scxml-compiler-for-the-qt-state-machine-framework/
#
# However, adding it to the CONFIG variable prevents us from specifying the
# generated output file name and directory
#CONFIG += scc

# Pre-build step
# These lines tell qmake how to make a new target object called "statemachine"
# Target artifact generated is the .h with the state machine definition:
statemachine.target = $$STATEMACHINE
# Commands to execute:
statemachine.commands = "scc -i $$STATECHART -o $$STATEMACHINE"
# Target is dependent on:
statemachine.depends = $$STATECHART

# There is one new target known as:
QMAKE_EXTRA_TARGETS += statemachine

# Tie one of these targets to the qmake build target
# Target artifact needs to exist before anything else can be done (which forces it to be made if it isn't already made)
PRE_TARGETDEPS += $$STATEMACHINE

# Remove auto generated header file on clean
QMAKE_CLEAN += $$STATEMACHINE

# Finally, add the generated state machine definition to the headers
HEADERS += $$STATEMACHINE

#
# SCC customizations
#
INCLUDEPATH += ../../../SCCLib/inc
LIBS += -L../../../SCCLib/out/debug -lscc
