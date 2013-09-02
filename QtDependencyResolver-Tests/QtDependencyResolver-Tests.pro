#-------------------------------------------------
#
# Project created by QtCreator 2013-08-31T16:40:49
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = $$qtLibraryTarget(QtDependencyResolver-Tests)
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
    MongoDBContext.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += $$PWD/../_bin
DEPENDPATH += $$PWD/../_bin

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../_bin/ -lQtDependencyResolverd
else:unix: LIBS += -L$$PWD/../_bin/ -lQtDependencyResolver

HEADERS += \
    IUsersService.h \
    RemoteUsersService.h \
    IUsersRepository.h \
    InMemoryUsersRepository.h \
    LocalUsersService.h \
    MongoUsersRepository.h \
    MongoDBContext.h
