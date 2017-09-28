#-------------------------------------------------
#
# Project created by QtCreator 2017-07-30T20:17:10
#
#-------------------------------------------------

QT       += core gui network

QT += concurrent
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Connectiher
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    Network/network.cpp \
    Model/room.cpp \
    View/mainwindow.cpp \
    Controller/settings.cpp \
    Controller/maincontroller.cpp \
    Model/model.cpp \
    Model/user.cpp \
    Controller/audiocontroller.cpp \
    View/createroomdialog.cpp \
    Network/serverroom.cpp

HEADERS  += \
    Network/network.h \
    Model/room.h \
    View/mainwindow.h \
    Controller/settings.h \
    Controller/maincontroller.h \
    Model/model.h \
    Model/user.h \
    Controller/audiocontroller.h \
    View/createroomdialog.h \
    Network/serverroom.h

FORMS    += View/mainwindow.ui \
    View/createroomdialog.ui
