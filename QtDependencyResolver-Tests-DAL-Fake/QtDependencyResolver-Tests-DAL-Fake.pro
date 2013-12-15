#-------------------------------------------------
#
# Project created by QtCreator 2013-11-13T14:13:38
#
#-------------------------------------------------

QT       -= gui

TARGET = QtDependencyResolver-Tests-DAL-Fake

unix: {
        CONFIG (debug, debug|release) {
                TARGET = QtDependencyResolver-Tests-DAL-Faked
        } else {
                TARGET = QtDependencyResolver-Tests-DAL-Fake
        }
} else {
        TARGET = $$qtLibraryTarget(QtDependencyResolver-Tests-DAL-Fake)
}

TEMPLATE = lib
DESTDIR = $$PWD/../_bin
CONFIG += debug_and_release build-all

DEFINES += QTDEPENDENCYRESOLVERTESTSDALFAKE_LIBRARY

SOURCES += \
    FakeRolesRepository.cpp \
    FakeUsersRepository.cpp

HEADERS +=\
        qtdependencyresolver-tests-dal-fake_global.h \
    FakeRolesRepository.h \
    FakeUsersRepository.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DAL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DALd
else:unix: LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DAL

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin
