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
    pathfinding.cpp \
    Animation.cpp \
    Janitor.cpp \
    Player.cpp \
    ResourceManager.cpp \
    Warcraft.cpp \
    entity/building/Building.cpp \
    entity/building/HumanBarracks.cpp \
    entity/building/HumanFarm.cpp \
    entity/unit/Footman.cpp \
    entity/unit/Grunt.cpp \
    entity/unit/Unit.cpp \
    entity/unit/Worker.cpp \
    entity/Entity.cpp \
    entity/Goldmine.cpp \
    entity/Trees.cpp \
    entity/building/HumanChurch.cpp \
    entity/building/HumanBlacksmith.cpp \
    entity/building/HumanLumberMill.cpp \
    entity/building/HumanStables.cpp \
    entity/building/HumanTower.cpp \
    entity/building/HumanTownHall.cpp \
    entity/building/OrcBarracks.cpp \
    entity/building/OrcBlacksmith.cpp \
    entity/unit/Daemon.cpp \
    entity/building/OrcTower.cpp \
    entity/building/OrcTownHall.cpp \
    entity/building/OrcTemple.cpp \
    entity/building/OrcLumberMill.cpp \
    entity/building/OrcKennels.cpp \
    entity/building/OrcFarm.cpp \
    ui/PeasantUI.cpp \
    ui/Message.cpp


HEADERS  += \
    Janitor.hpp \
    Animation.hpp \
    ResourceManager.hpp \
    entity/building/Building.hpp \
    entity/building/HumanBarracks.hpp \
    entity/unit/Unit.hpp \
    entity/unit/Worker.hpp \
    entity/unit/Grunt.hpp \
    entity/unit/Footman.hpp \
    entity/unit/Daemon.hpp \
    entity/Entity.hpp \
    entity/Goldmine.hpp \
    entity/Trees.hpp \
    Player.hpp \
    pathfinding.hpp \
    Warcraft.hpp \
    entity/building/HumanBlacksmith.hpp \
    entity/building/HumanChurch.hpp \
    entity/building/HumanFarm.hpp \
    entity/building/HumanLumberMill.hpp \
    entity/building/HumanStables.hpp \
    entity/building/HumanTower.hpp \
    entity/building/HumanTownHall.hpp \
    entity/building/OrcBarracks.hpp \
    entity/building/OrcBlacksmith.hpp \
    entity/building/OrcFarm.hpp \
    entity/building/OrcKennels.hpp \
    entity/building/OrcLumberMill.hpp \
    entity/building/OrcTemple.hpp \
    entity/building/OrcTower.hpp \
    entity/building/OrcTownHall.hpp \
    ui/PeasantUI.hpp \
    entity/building/buildings_all.hpp \
    Race.hpp \
    ui/Message.hpp


FORMS    +=

RESOURCES += \
    gameresources.qrc

DISTFILES += \
    _config.yml \
    res/BUILDINGS_H.png \
    res/BUILDINGS_O.png \
    preview_040617.PNG \
    README.md
