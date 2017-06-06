#ifndef PLAYER_H
#define PLAYER_H

#include "entity/building/building.h"
#include "entity/unit/unit.h"
#include "entity/unit/worker.h"

class Player
{
public:
    Player(Race race);

    void addGold(int amount);
    void addLumber(int amount);
    void addFood(int amount);

    QList<Building *> *getBuildings();
    QList<Unit *> *getUnits();


    void build(Building *building, Worker *worker);


protected:
    Race race;

    QList<Building *>   buildings;
    QList<Unit *>       units;
    QList<Worker *>     workers;


    int gold;
    int lumber;
    int food;
};

#endif // PLAYER_H
