#-------------------------------------------------
#
# Project created by QtCreator 2014-02-21T11:32:36
#
#-------------------------------------------------

QT       -= gui
QT       += widgets

TARGET = HidLib
TEMPLATE = lib

DEFINES += HIDLIB_LIBRARY

SOURCES += hidlib.cpp \
        hidreceiver.cpp \
        receiverdata.cpp \
        bytebuffer.cpp \
        receiverthread.cpp \
    hidnotfoundexception.cpp

HEADERS += hidlib.h\
        hidlib_global.h \
        hidreceiver.h \
        receiverdata.h \
        bytebuffer.h \
        receiverthread.h \
        hidapi.h \
        HidLibConstants.h \
    hidnotfoundexception.h

#CONFIG += build_all

release:DESTDIR = release
release:OBJECTS_DIR = release/.obj
release:MOC_DIR = release/.moc
release:RCC_DIR = release/.rcc
release:UI_DIR = release/.ui

debug:DESTDIR = debug
debug:OBJECTS_DIR = debug/.obj
debug:MOC_DIR = debug/.moc
debug:RCC_DIR = debug/.rcc
debug:UI_DIR = debug/.ui

#CONFIG(debug, debug|release) {

#LIBS += -L"$$_PRO_FILE_PWD_/3rdparty/libs/" -lhidapi
#INCLUDEPATH += -L"$$_PRO_FILE_PWD_/3rdparty/include/"

##    OBJECTS_DIR = build/debug
##    # Подключаем debug-версии библиотек для разных платформ
##    win32: LIBS += -Llib -lhidapi
##    unix: LIBS += -Llib -L. -lhidapid -Wl,-rpath,lib -Wl,-rpath,.
##} else {
##    OBJECTS_DIR = build/release
##    # Подключаем release-версии библиотек для разных платформ
##    win32: LIBS += -Llib -lhidapi
##    unix: LIBS += -Llib -L. -lhidapi -Wl,-rpath,lib -Wl,-rpath,.
#}

##unix {
##    target.path = /usr/lib
##    INSTALLS += target
##}



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/3rdparty/libs/ -lhidapi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/3rdparty/libs/ -lhidapid
else:unix: LIBS += -L$$PWD/3rdparty/libs/ -lhidapi

INCLUDEPATH += $$PWD/3rdparty/include
DEPENDPATH += $$PWD/3rdparty/include
