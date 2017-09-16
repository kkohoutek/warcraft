#include "Player.hpp"
#include <QDebug>
#include <QGraphicsScene>


Player::Player(Race race) {
    this->race = race;

    goldDestinationIndex = 0;
    lumberDestinationIndex = 0;

    selectedUnits.reserve(MAX_SELECTED_UNITS);
}

void Player::update(){
    for(Unit *unit : units){
        unit->update();
    }
    for(Building *building : buildings){
        building->update();
    }
}


void Player::selectUnit(Unit *unit){
    if(units.contains(unit)){
        deselect();
        selectedUnits.append(unit);
        unit->setHighlighted(true);
    }
}

void Player::selectUnits(QList<Unit *> selected){
    if(selected.empty()) return;

    if(selected.size() > MAX_SELECTED_UNITS){
        selected = selected.mid(0, MAX_SELECTED_UNITS);
    }

    deselect();
    for(Unit *u : selected){
        if(units.contains(u)){
            selectedUnits.append(u);
            u->setHighlighted(true);
        }
    }
}

void Player::selectBuilding(Building *building){
    if(buildings.contains(building)){
        deselect();
        selectedBuilding = building;
        selectedBuilding->setHighlighted(true);
    }
}

void Player::deselect() {
    for(Unit * u : selectedUnits){
        u->setHighlighted(false);
    }
    selectedUnits.clear();

    if(selectedBuilding){
        selectedBuilding->setHighlighted(false);
        selectedBuilding = nullptr;
    }
}

void Player::newBuilding(Building *building, Worker *worker, int costGold, int costLumber) {
    if(!units.contains(worker)) return;

    if(gold >= costGold && lumber >= costLumber){
        gold -= costGold;
        lumber -= costLumber;
        worker->build(building);
        buildings.append(building);
        deselect();
    }
}



QList<Building *> &Player::getBuildings() {
    return buildings;
}

QList<Unit *> &Player::getUnits(){
    return units;
}

QList<Unit *> &Player::getSelectedUnits() {
    return selectedUnits;
}

Race Player::getRace() const {
    return race;

}

Building *Player::goldDestination() const {
    return buildings[goldDestinationIndex];
}

Building *Player::lumberDestination() const {
    return buildings[lumberDestinationIndex];
}
