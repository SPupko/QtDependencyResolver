#-------------------------------------------------
#
# Project created by QtCreator 2013-08-31T16:40:49
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

unix: {
        CONFIG (debug, debug|release) {
                TARGET = QtDependencyResolver-Testsd
        } else {
                TARGET = QtDependencyResolver-Tests
        }
} else {
        TARGET = $$qtLibraryTarget(QtDependencyResolver-Tests)
}

CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
DESTDIR = $$PWD/../_tests


SOURCES += DIContainerTest.cpp \
    IUsersService.cpp \
    RemoteUsersService.cpp \
    IUsersRepository.cpp \
    InMemoryUsersRepository.cpp \
    LocalUsersService.cpp \
    MongoUsersRepository.cpp \
    MongoDBContext.cpp \
    Person.cpp \
    Team.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolverd
else:unix:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver
else:unix:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolverd

HEADERS += \
    IUsersService.h \
    RemoteUsersService.h \
    IUsersRepository.h \
    InMemoryUsersRepository.h \
    LocalUsersService.h \
    MongoUsersRepository.h \
    MongoDBContext.h \
    Person.h \
    Team.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLLd
else:unix: LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLL

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLL-Native
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLL-Natived
else:unix: LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-BLL-Native

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DAL
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DALd
else:unix: LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DAL

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DAL-Fake
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DAL-Faked
else:unix: LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver-Tests-DAL-Fake

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin
