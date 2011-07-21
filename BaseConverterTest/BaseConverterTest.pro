#-------------------------------------------------
#
# Project created by QtCreator 2011-07-21T10:22:32
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_baseconvertertest
CONFIG   += console


TEMPLATE = app


SOURCES += tst_baseconvertertest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BaseConverter-build-desktop/release/ -lBaseConverter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BaseConverter-build-desktop/debug/ -lBaseConverter
else:symbian: LIBS += -lBaseConverter
else:unix: LIBS += -L$$PWD/../BaseConverter-build-desktop/ -lBaseConverter

INCLUDEPATH += $$PWD/../BaseConverter
DEPENDPATH += $$PWD/../BaseConverter

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../BaseConverter-build-desktop/release/BaseConverter.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../BaseConverter-build-desktop/debug/BaseConverter.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/../BaseConverter-build-desktop/libBaseConverter.a
