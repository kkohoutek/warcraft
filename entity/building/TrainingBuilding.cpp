#include "TrainingBuilding.hpp"
#include <QGraphicsScene>

#define TRAINING_QUEUE_CAP 5

TrainingBuilding::TrainingBuilding(QPointF pos, Building::Type type,
                                   bool finishedOnSpawn, Race race,
                                   const QList<int> &preFrame,
                                   const QList<int> &endFrame,
                                   int buildTime,
                                   int maxHP,
                                   ResourceManager *rm,
                                   Player *player)
    : Building(pos, type, finishedOnSpawn, race, preFrame, endFrame, buildTime, maxHP, rm)
{
    this->player = player;
    connect(&trainingTimer, SIGNAL(timeout()), this, SLOT(dequeueUnit()));
}

TrainingBuilding::~TrainingBuilding() {
    qDeleteAll(trainingQueue);
}

bool TrainingBuilding::enqueueUnit(Unit *unit, int sec) {
    if(isQueueFull()) return false;
    trainingQueue.enqueue(unit);;
    if(!trainingTimer.isActive()){
        trainingTimer.start(sec*1000);
    }
    return true;
}

int TrainingBuilding::unitsInQueue() const {
    return trainingQueue.size();
}

bool TrainingBuilding::isQueueFull() const {
    return unitsInQueue() >= TRAINING_QUEUE_CAP;
}

void TrainingBuilding::dequeueUnit() {
    auto u = trainingQueue.dequeue();
    scene()->addItem(u);
    player->getUnits().prepend(u);

    if(trainingQueue.isEmpty()) {
        trainingTimer.stop();
    }
}

void TrainingBuilding::die() {
    qDeleteAll(trainingQueue);
    Building::die();
}



