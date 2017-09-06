#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "entity/unit/unit.h"
#include "entity/unit/worker.h"

#define MAX_SELECTED_UNITS 1

class Player : public QObject
{

public:
    Player(Race race);

    void update();

    void newBuilding(Building *building, Worker *worker, int costGold, int costLumber);

    void addFood(int amount);
    void addGold(int amount);
    void addLumber(int amount);

    int &getGold();
    int &getLumber();
    int &getFood();

    void selectUnit(Unit *unit);
    void selectUnits(QList<Unit *> selected);
    void selectBuilding(Building *building);
    void deselect();

    QList<Building *> &getBuildings();
    QList<Unit *> &getUnits();
    QList<Worker *> &getWorkers();
    QList<Unit *> &getSelectedUnits();
    QList<Worker *> selectedWorkers() const;
    QList<Unit *> allUnits() const;              // units + workers

    Race getRace() const;
    Building *goldDestination() const;
    Building *lumberDestination() const;


protected:
    Race race;

    QList<Building *>   buildings;
    QList<Unit *>       units;
    QList<Worker *>     workers;
    QList<Unit *>       selectedUnits;

    Building *selectedBuilding = nullptr;


    int gold = 0;
    int lumber = 0;
    int food = 0;

    int goldDestinationIndex;   // index v buildings
    int lumberDestinationIndex; // index v buildings
};

#endif // PLAYER_H
