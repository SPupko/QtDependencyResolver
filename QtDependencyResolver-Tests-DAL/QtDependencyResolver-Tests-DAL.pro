#-------------------------------------------------
#
# Project created by QtCreator 2013-11-13T14:12:55
#
#-------------------------------------------------

QT       -= gui

unix: {
        CONFIG (debug, debug|release) {
                TARGET = QtDependencyResolver-Tests-DALd
        } else {
                TARGET = QtDependencyResolver-Tests-DAL
        }
} else {
        TARGET = $$qtLibraryTarget(QtDependencyResolver-Tests-DAL)
}

TEMPLATE = lib
DESTDIR = $$PWD/../_bin
CONFIG += debug_and_release build-all

DEFINES += QTDEPENDENCYRESOLVERTESTSDAL_LIBRARY

SOURCES += \
    IRolesRepository.cpp \
    IUsersRepository.cpp

HEADERS +=\
        qtdependencyresolver-tests-dal_global.h \
    IRolesRepository.h \
    IUsersRepository.h

