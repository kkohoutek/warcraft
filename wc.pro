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
    entity/building/building.cpp \
    entity/unit/unit.cpp \
    entity/building/humanfarm.cpp \
    entity/building/humanblacksmith.cpp

HEADERS  += mainwindow.h \
    entity/entity.h \
    animation.h \
    warcraft.h \
    entity/building/building.h \
    entity/unit/unit.h \
    common.h \
    entity/building/humanfarm.h \
    entity/building/humanblacksmith.h

FORMS    += mainwindow.ui

RESOURCES += \
    gameresources.qrc
