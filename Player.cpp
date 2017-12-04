#include "Player.hpp"
#include <QDebug>
#include <QGraphicsScene>
#include <QMutableListIterator>

#define MAX_SELECTED_UNITS 8
#define MAX_FOOD           100
#define MAX_GOLD           40000
#define MAX_LUMBER         20000

bool Player::deleteDead = false;
int Player::maxDead = 8;

Player::Player(Race race) {
    this->race = race;
    selectedUnits.reserve(MAX_SELECTED_UNITS);
}

void Player::update(){
    for(Unit *unit : units){
        unit->update();
        if(!unit->isAlive()){
            if(unit->isHighlighted()){
                unit->setHighlighted(false);

                QMutableListIterator<Unit *> i(selectedUnits);
                while(i.hasNext()){
                    Unit *next = i.next();
                    if(next == unit){
                        i.remove();
                        break;
                    }
                }
            }
            if(deleteDead && !delQueue.contains(unit)) {
                delQueue.enqueue(unit);
                cleanUp();
            }
        }
    }
    for(Building *building : buildings){
        building->update();
        if(!building->isAlive()){
            if(selectedBuilding == building){
                building->setHighlighted(false);
                selectedBuilding = nullptr;
            }

            if(!delQueue.contains(building)) {
                delQueue.enqueue(building);
                cleanUp();
            }
        }
    }
}

void Player::selectUnit(Unit *unit){
    if(units.contains(unit)){
        deselect();
        selectedUnits.append(unit);
        unit->setHighlighted(true);
    }
}

void Player::selectUnits(QList<Unit *> &selected){
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

void Player::cleanUp() {
    if(delQueue.size() <= maxDead) return;
    Entity *e = delQueue.dequeue();
    buildings.removeOne(reinterpret_cast<Building *>(e));
    units.removeOne(reinterpret_cast<Unit *>(e));
    e->scene()->removeItem(e);
    delete e;
}
