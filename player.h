#ifndef PLAYER_H
#define PLAYER_H

#include "entity/unit/unit.h"
#include "entity/unit/worker.h"

class Player
{
public:
    Player(Race race);

    void update();

    void newBuilding(Building *building, Worker *worker, int costGold, int costLumber);

    void addGold(int amount);
    void addLumber(int amount);
    void addFood(int amount);

    int getGold();
    int getLumber();
    int getFood();

    void selectUnit(Unit *unit);
    void selectUnits(QList<Unit *> selected);
    void selectBuilding(Building *building);

    QList<Building *> *getBuildings();
    QList<Unit *> *getUnits();
    QList<Worker *> *getWorkers();
    QList<Unit *> *getSelectedUnits();



protected:
    Race race;

    QList<Building *>   buildings;
    QList<Unit *>       units;
    QList<Worker *>     workers;
    QList<Unit *>       selectedUnits;

    Building *selectedBuilding = NULL;


    int gold = 0;
    int lumber = 0;
    int food = 0;
};

#endif // PLAYER_H
