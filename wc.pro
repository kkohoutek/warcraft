#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T15:22:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entity/entity.cpp \
    animation.cpp \
    warcraft.cpp \
    entity/building/building.cpp

HEADERS  += mainwindow.h \
    entity/entity.h \
    animation.h \
    warcraft.h \
    entity/building/building.h

FORMS    += mainwindow.ui
