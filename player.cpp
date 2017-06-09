#include "player.h"

Player::Player(Race race) {
    this->race = race;
}

void Player::update(){



    for(Worker *worker : workers){
        worker->update();
    }
    for(Unit *unit : units){
        unit->update();
    }

    for(Building *building : buildings){
        building->update();
    }

}


void Player::newBuilding(Building *building, Worker *worker, int costGold, int costLumber) {
    if(!workers.contains(worker)) return;

    if(gold > costGold && lumber > costLumber){
        gold-=costGold;
        lumber-=costLumber;
        worker->goBuild(building);
        buildings.append(building);

        selectedUnits.clear();
    }

}



void Player::selectUnit(Unit *unit){
    if(units.contains(unit) || workers.contains(static_cast<Worker *>(unit))){
        deselect();
        selectedUnits.append(unit);
        unit->setHighlighted(true);
    }
}

void Player::selectUnits(QList<Unit *> selected){
    for(Unit *u : selected){
        if(units.contains(u)){
            deselect();
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

    if(selectedBuilding != NULL){
        selectedBuilding->setHighlighted(false);
        selectedBuilding = NULL;
    }
}

void Player::addGold(int amount) {
    gold += amount;
}

void Player::addLumber(int amount) {
    lumber += amount;
}

void Player::addFood(int amount) {
    food += amount;
}

int Player::getGold(){
    return gold;
}

int Player::getLumber(){
    return lumber;
}

int Player::getFood(){
    return food;
}

QList<Building *> &Player::getBuildings() {
    return buildings;
}

QList<Unit *> &Player::getUnits() {
    return units;

}

QList<Worker *> &Player::getWorkers(){
    return workers;
}

QList<Unit *> &Player::getSelectedUnits(){
    return selectedUnits;
}
