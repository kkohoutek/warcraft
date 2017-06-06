#include "worker.h"
#include <QGraphicsScene>
#include <QDebug>

Worker::Worker(QPointF pos, Race race) : Unit(pos, 1, 0, 0, 0)
{
    setMaxHP(40);
    setHP(40);

    switch(race){
        case HUMAN:
    {
            QPixmap *spriteSheet = new QPixmap(":graphics/FOOTMAN");

            QList<QList<int>> *walk0DegFrames = new QList<QList<int>>();
            walk0DegFrames->append(QList<int>() << 2 << 0);
            walk0DegFrames->append(QList<int>() << 2 << 1);
            walk0DegFrames->append(QList<int>() << 2 << 2);
            walk0DegFrames->append(QList<int>() << 2 << 1);
            setCurrentAnimation(new Animation(spriteSheet, 48, 48, walk0DegFrames, 250, true));
            //peasant
            break;
    }

        case ORC:
            //peon
            break;
    }
}

QRectF Worker::boundingRect() const {
    return QRectF(6,6,36,36);

}

void Worker::gatherGold(Goldmine *source, Building *destination){
    currentGoldmine = source;
    goldDestination = destination;
    currentTree = NULL;
    setTarget(currentGoldmine->pos());
}

void Worker::gatherLumber(Tree *source, Building *destination){
    currentTree = source;
    lumberDestination = destination;
    currentGoldmine = NULL;
    setTarget(currentTree->pos());
}

void Worker::stopGathering(){
    currentGoldmine = NULL;
    currentTree = NULL;
}

void Worker::goBuild(Building *building){
    currentBuilding = building;
    setTarget(currentBuilding->pos());
}

void Worker::update(){

    if(currentBuilding != NULL){
        if(!currentBuilding->isBuildingFinished()){
            if(collidesWithItem(currentBuilding)){
                currentBuilding->beginConstruction();
                scene()->addItem(currentBuilding);
                setVisible(false);
            } else {
                moveToTarget();
            }
        } else {
            setVisible(true);
            setPos(currentBuilding->pos()-QPointF(0,8));
            currentBuilding = NULL;
        }
    }

}

bool Worker::isGatheringGold(){
    return currentGoldmine != NULL;
}

bool Worker::isGatheringLumber(){
    return currentTree = NULL;
}

bool Worker::isBuilding(){
    return currentBuilding != NULL;
}
