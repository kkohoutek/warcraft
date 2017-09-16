#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity/unit/Unit.hpp"
#include "entity/unit/Worker.hpp"

#define MAX_SELECTED_UNITS 4

class Player
{

public:
    int gold = 0;
    int lumber = 0;
    int food = 0;

    Player(Race race);

    void update();

    void selectUnit(Unit *unit);
    void selectUnits(QList<Unit *> selected);
    void selectBuilding(Building *building);
    void deselect();
    void newBuilding(Building *building, Worker *worker, int costGold, int costLumber);

    QList<Building *> &getBuildings();
    QList<Unit *> &getUnits();
    QList<Unit *> &getSelectedUnits();

    Race getRace() const;
    Building *goldDestination() const;
    Building *lumberDestination() const;

protected:
    Race race;

    QList<Building *>   buildings;
    QList<Unit *>       units;
    QList<Unit *>       selectedUnits;

    Building *selectedBuilding = nullptr;

    int goldDestinationIndex;   // Index v buildings
    int lumberDestinationIndex; // Index v buildings
};

#endif // PLAYER_HPP
