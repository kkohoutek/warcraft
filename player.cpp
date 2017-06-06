#include "player.h"

Player::Player(Race race) {
    this->race = race;
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
