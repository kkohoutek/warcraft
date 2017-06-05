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
    entity/building/humanblacksmith.cpp \
    entity/building/humantownhall.cpp \
    entity/building/humanbarracks.cpp \
    entity/building/humanlumbermill.cpp \
    entity/building/humanstables.cpp \
    entity/building/humanchurch.cpp \
    entity/building/humantower.cpp \
    entity/unit/footman.cpp \
    player.cpp \
    entity/goldmine.cpp \
    entity/unit/worker.cpp \
    entity/tree.cpp

HEADERS  += mainwindow.h \
    entity/entity.h \
    animation.h \
    warcraft.h \
    entity/building/building.h \
    entity/unit/unit.h \
    common.h \
    entity/building/humanfarm.h \
    entity/building/humanblacksmith.h \
    entity/building/humantownhall.h \
    entity/building/humanbarracks.h \
    entity/building/humanlumbermill.h \
    entity/building/humanstables.h \
    entity/building/humanchurch.h \
    entity/building/humantower.h \
    entity/unit/footman.h \
    player.h \
    entity/goldmine.h \
    entity/unit/worker.h \
    entity/tree.h

FORMS    += mainwindow.ui

RESOURCES += \
    gameresources.qrc
