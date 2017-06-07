#include "player.h"

Player::Player(Race race) {
    this->race = race;
}

void Player::update(){
    for(Unit *unit : units){
        unit->update();
    }

    for(Worker *worker : workers){
        worker->update();
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
    selectedUnits.clear();
    if(units.contains(unit) || workers.contains(static_cast<Worker *>(unit))){
        selectedUnits.append(unit);
        unit->setHighlighted(true);
    }
}

void Player::selectUnits(QList<Unit *> selected){
    selectedUnits.clear();
    for(Unit *u : selected){
        if(units.contains(u)){
            selectedUnits.append(u);
            u->setHighlighted(true);
        }
    }
}

void Player::selectBuilding(Building *building){
    if(buildings.contains(building)){
        selectedBuilding = building;
        selectedBuilding->setHighlighted(true);
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

QList<Building *> *Player::getBuildings() {
    return &buildings;
}

QList<Unit *> *Player::getUnits() {
    return &units;

}

QList<Worker *> *Player::getWorkers(){
    return &workers;
}

QList<Unit *> *Player::getSelectedUnits(){
    return &selectedUnits;
}
