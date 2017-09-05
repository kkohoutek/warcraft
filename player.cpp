#include "player.h"
#include <QDebug>
#include <QGraphicsScene>


Player::Player(Race race) {
    this->race = race;

    goldDestinationIndex = 0;
    lumberDestinationIndex = 0;

    selectedUnits.reserve(MAX_SELECTED_UNITS);
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

    if(gold >= costGold && lumber >= costLumber){
        gold-=costGold;
        lumber-=costLumber;
        worker->goBuild(building);
        buildings.append(building);
        deselect();
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
    if(selected.empty()) return;

    if(selected.size() > MAX_SELECTED_UNITS){
        selected = selected.mid(0, MAX_SELECTED_UNITS);
    }

    deselect();
    for(Unit *u : selected){
        if(units.contains(u) || workers.contains(static_cast<Worker *>(u))){
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

void Player::selectedMoveTo(QPointF target, int gap){
    int i = 0 ;
    for(Unit *unit : selectedUnits){
        unit->cancel();
        unit->setTarget(target+QPoint(0,i));
        unit->move();
        i +=gap;
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

int &Player::getGold() {
    return gold;
}

int &Player::getLumber() {
    return lumber;
}

int &Player::getFood() {
    return food;
}

QList<Building *> &Player::getBuildings() {
    return buildings;
}

QList<Unit *> &Player::getUnits(){
    return units;
}

QList<Worker *> &Player::getWorkers() {
    return workers;
}

QList<Unit *> &Player::getSelectedUnits() {
    return selectedUnits;
}

QList<Worker *> Player::selectedWorkers() const {
    QList<Worker *> selectedWorkers;
    for(Unit *u : selectedUnits){
        if(workers.contains(static_cast<Worker *>(u))){
            selectedWorkers.append(static_cast<Worker *>(u));
        }
    }
    return selectedWorkers;

}

QList<Unit *> Player::allUnits() const {
    QList<Unit *> all;
    all.append(units);
    for(Worker *w : workers){
        all.append(w);
    }
    return all;
}

Race Player::getRace() const {
    return race;

}

Building *Player::goldDestination() const {
    return buildings.at(goldDestinationIndex);
}

Building *Player::lumberDestination() const {
    return buildings.at(lumberDestinationIndex);
}
