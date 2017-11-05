#include "TrainingBuilding.hpp"
#include <QGraphicsScene>


TrainingBuilding::TrainingBuilding(QPointF pos, Building::Type type,
                                   bool finishedOnSpawn, Race race,
                                   const QList<int> &preFrame,
                                   const QList<int> &endFrame,
                                   int buildTime,
                                   int maxHP,
                                   ResourceManager *rm) : Building(pos, type, finishedOnSpawn, race, preFrame, endFrame, buildTime, maxHP, rm)
{
    //trainingTimer.setSingleShot(true);
    connect(&trainingTimer, SIGNAL(timeout()), this, SLOT(dequeueUnit()));
}

TrainingBuilding::~TrainingBuilding() {

}

bool TrainingBuilding::enqueueUnit(Unit *unit, int sec) {
    if(isQueueFull()) return false;
    trainingQueue.enqueue(unit);
    if(!trainingTimer.isActive()){
        trainingTimer.start(sec*1000);
    }
    return true;
}

int TrainingBuilding::unitsInQueue() const {
    return trainingQueue.size();
}

bool TrainingBuilding::isQueueFull() const {
    return unitsInQueue() >= 5;
}

void TrainingBuilding::dequeueUnit() {
    scene()->addItem(trainingQueue.dequeue());
    if(trainingQueue.isEmpty()) {
        trainingTimer.stop();
    }
}


