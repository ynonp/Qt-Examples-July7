#-------------------------------------------------
#
# Project created by QtCreator 2011-07-21T10:03:27
#
#-------------------------------------------------

TARGET = BaseConverter
TEMPLATE = lib
CONFIG += staticlib

SOURCES += baseconverter.cpp \
    mainwindow.cpp

HEADERS += baseconverter.h \
    mainwindow.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

FORMS += \
    mainwindow.ui
