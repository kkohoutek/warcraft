#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity/unit/Unit.hpp"
#include "entity/building/Building.hpp"

// Tato třída se stará o hráče.
class Player
{
public:
    int gold = 0;
    int lumber = 0;
    int food = 0;

    Player(Race race);

    void selectUnit(Unit *unit);
    void selectUnits(QList<Unit *> &selected);
    void selectBuilding(Building *building);
    void deselect();

    QLinkedList<Building *>   &getBuildings()               { return buildings; }
    QLinkedList<Unit *>       &getUnits()                   { return units; }
    QList<Unit *>             &getSelectedUnits()           { return selectedUnits; }
    Building                  *getSelectedBuilding() const  { return selectedBuilding; }

    Race getRace() const                        { return race; }

private:
    QLinkedList<Building *>   buildings;
    QLinkedList<Unit *>       units;
    QList<Unit *>       selectedUnits;

    Building *selectedBuilding = nullptr;

    Race race;  
};

#endif // PLAYER_HPP
