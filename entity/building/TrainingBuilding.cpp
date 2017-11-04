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

void TrainingBuilding::enqueueUnit(Unit *unit, int sec) {
    trainingQueue.enqueue(unit);
    if(!trainingTimer.isActive()){
        trainingTimer.start(sec*1000);
    }
}

void TrainingBuilding::dequeueUnit() {
    scene()->addItem(trainingQueue.dequeue());
    if(trainingQueue.isEmpty()) {
        trainingTimer.stop();
    }
}


