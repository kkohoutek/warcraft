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

    QLinkedList<Building *>   &getBuildings()               { return buildings; }
    QLinkedList<Unit *>       &getUnits()                   { return units; }
    QList<Unit *>             &getSelectedUnits()           { return selectedUnits; }
    Building                  *getSelectedBuilding() const  { return selectedBuilding; }

    Race getRace() const                        { return race; }

protected:
    QLinkedList<Building *>   buildings;
    QLinkedList<Unit *>       units;
    QList<Unit *>       selectedUnits;

    Building *selectedBuilding = nullptr;

private:
    Race race;
};

#endif // PLAYER_HPP
