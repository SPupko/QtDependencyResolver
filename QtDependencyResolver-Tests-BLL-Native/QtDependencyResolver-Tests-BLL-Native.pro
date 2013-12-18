#-------------------------------------------------
#
# Project created by QtCreator 2013-11-13T14:12:09
#
#-------------------------------------------------

QT       -= gui

unix: {
        CONFIG (debug, debug|release) {
                TARGET = QtDependencyResolver-Tests-BLL-Natived
        } else {
                TARGET = QtDependencyResolver-Tests-BLL-Native
        }
} else {
        TARGET = $$qtLibraryTarget(QtDependencyResolver-Tests-BLL-Native)
}

TEMPLATE = lib
DESTDIR = $$PWD/../_bin
CONFIG += debug_and_release build-all

DEFINES += QTDEPENDENCYRESOLVERTESTSBLLNATIVE_LIBRARY

SOURCES += \
    NativeUsersDomainModel.cpp \
    NativeRolesDomainModel.cpp \
    NativeComplexDomainModel.cpp

HEADERS +=\
        qtdependencyresolver-tests-bll-native_global.h \
    NativeUsersDomainModel.h \
    NativeRolesDomainModel.h \
    NativeComplexDomainModel.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLLd
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLL
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLLd

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin
