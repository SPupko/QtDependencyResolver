#-------------------------------------------------
#
# Project created by QtCreator 2013-11-13T14:10:01
#
#-------------------------------------------------

QT       -= gui

TARGET = QtDependencyResolver-BLL-Native
TEMPLATE = lib

DEFINES += QTDEPENDENCYRESOLVERBLLNATIVE_LIBRARY

SOURCES += QtDependencyResolverBLLNative.cpp

HEADERS += QtDependencyResolverBLLNative.h\
        qtdependencyresolver-bll-native_global.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
