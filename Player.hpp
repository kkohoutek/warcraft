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

    QList<Building *>   &getBuildings()         { return buildings; }
    QList<Unit *>       &getUnits()             { return units; }
    QList<Unit *>       &getSelectedUnits()     { return selectedUnits; }

    Race getRace() const                        { return race; }

protected:
    QList<Building *>   buildings;
    QList<Unit *>       units;
    QList<Unit *>       selectedUnits;

    Building *selectedBuilding = nullptr;

private:
    Race race;
};

#endif // PLAYER_HPP
