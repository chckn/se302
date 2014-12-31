#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T23:47:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    mylang.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    libmylang.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../release/ -lmylang
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../debug/ -lmylang
else:symbian: LIBS += -lmylang
else:unix: LIBS += -L$$PWD/../ -lmylang

INCLUDEPATH += $$PWD/../
DEPENDPATH += $$PWD/../

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../release/mylang.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../debug/mylang.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/../libmylang.a
