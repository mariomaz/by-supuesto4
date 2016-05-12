#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T12:16:18
#
#-------------------------------------------------

QT       += network
QT       -= gui

TARGET = shared
TEMPLATE = lib
CONFIG += staticlib

SOURCES += command.cpp \
    response.cpp \
    sender.cpp \
    receiver.cpp

HEADERS += command.h \
    response.h \
    sender.h \
    receiver.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
