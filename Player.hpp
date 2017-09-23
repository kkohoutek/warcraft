#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity/unit/Unit.hpp"
#include "entity/unit/Worker.hpp"

class Player
{

public:
    int gold = 0;
    int lumber = 0;
    int food = 0;

    Player(Race race);

    void update();

    void selectUnit(Unit *unit);
    void selectUnits(QList<Unit *> &selected);
    void selectBuilding(Building *building);
    void deselect();
    void newBuilding(Building *building, Worker *worker, int costGold, int costLumber);

    QList<Building *>   &getBuildings()         { return buildings; }
    QList<Unit *>       &getUnits()             { return units; }
    QList<Unit *>       &getSelectedUnits()     { return selectedUnits; }

    Race getRace() const                        { return race; }

protected:
    Race race;

    QList<Building *>   buildings;
    QList<Unit *>       units;
    QList<Unit *>       selectedUnits;

    Building *selectedBuilding = nullptr;
};

#endif // PLAYER_HPP
