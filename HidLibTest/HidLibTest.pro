#-------------------------------------------------
#
# Project created by QtCreator 2015-07-09T16:59:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HidLibTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/3rdparty/libs/ -lHidLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/3rdparty/libs/ -lHidLibd
else:unix: LIBS += -L$$PWD/3rdparty/libs/ -lHidLib

INCLUDEPATH += $$PWD/3rdparty/include
DEPENDPATH += $$PWD/3rdparty/include
