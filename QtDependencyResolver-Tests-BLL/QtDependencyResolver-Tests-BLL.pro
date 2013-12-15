#-------------------------------------------------
#
# Project created by QtCreator 2013-11-13T14:08:35
#
#-------------------------------------------------

QT       -= gui

unix: {
        CONFIG (debug, debug|release) {
                TARGET = QtDependencyResolver-Tests-BLLd
        } else {
                TARGET = QtDependencyResolver-Tests-BLL
        }
} else {
        TARGET = $$qtLibraryTarget(QtDependencyResolver-Tests-BLL)
}

TEMPLATE = lib
DESTDIR = $$PWD/../_bin
CONFIG += debug_and_release build-all

DEFINES += QTDEPENDENCYRESOLVERTESTSBLL_LIBRARY

SOURCES += \
    IRolesDomainModel.cpp \
    IUsersDomainModel.cpp \
    IComplexDomainModel.cpp

HEADERS +=\
        qtdependencyresolver-tests-bll_global.h \
    IRolesDomainModel.h \
    IUsersDomainModel.h \
    IComplexDomainModel.h
