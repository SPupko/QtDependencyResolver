#-------------------------------------------------
#
# Project created by QtCreator 2013-08-31T16:26:00
#
#-------------------------------------------------

QT       -= gui

TARGET = $$qtLibraryTarget(QtDependencyResolver)
TEMPLATE = lib
DESTDIR = $$PWD/../_bin
CONFIG += debug_and_release build-all

DEFINES += QTDEPENDENCYRESOLVER_LIBRARY

SOURCES += \
    DIContainer.cpp

HEADERS +=\
        qtdependencyresolver_global.h \
    DIContainer.h

