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
    entity/unit/grunt.cpp \
    player.cpp \
    entity/goldmine.cpp \
    entity/unit/worker.cpp \
    entity/building/orcbarracks.cpp \
    entity/building/orcfarm.cpp \
    entity/building/orckennels.cpp \
    entity/building/orclumbermill.cpp \
    entity/building/orctemple.cpp \
    entity/building/orctower.cpp \
    entity/building/orctownhall.cpp \
    entity/building/orcblacksmith.cpp \
    entity/trees.cpp \
    entity/unit/daemon.cpp \
    garbagecollector.cpp \
    pathfinding/graph.cpp \
    resourcemanager.cpp


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
    entity/unit/grunt.h \
    player.h \
    entity/goldmine.h \
    entity/unit/worker.h \
    entity/trees.h \
    entity/building/orcbarracks.h \
    entity/building/orcfarm.h \
    entity/building/orckennels.h \
    entity/building/orclumbermill.h \
    entity/building/orctemple.h \
    entity/building/orctower.h \
    entity/building/orctownhall.h \
    entity/building/orcblacksmith.h \
    entity/unit/daemon.h \
    garbagecollector.h \
    pathfinding/graph.h \
    resourcemanager.h


FORMS    += mainwindow.ui

RESOURCES += \
    gameresources.qrc

DISTFILES += \
    _config.yml \
    res/BUILDINGS_H.png \
    res/BUILDINGS_O.png \
    res/WORLD_bad.png \
    preview_040617.PNG \
    res/BUILDINGS_H.xcf \
    res/BUILDINGS_O.xcf \
    res/WORLD.xcf \
    README.md
