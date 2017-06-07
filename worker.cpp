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

        /* ****** PEASANT ****** */
        QPixmap *spriteSheet = new QPixmap(":graphics/PEASANT");
        QPixmap *spriteSheetFlipped = new QPixmap(":graphics/PEASANT2");

        movementAnims = new QList<Animation *>();

        QList<QList<int>> *walk0DegFrames = new QList<QList<int>>();
        walk0DegFrames->append(QList<int>() << 1 << 3);
        walk0DegFrames->append(QList<int>() << 2 << 3);
        walk0DegFrames->append(QList<int>() << 3 << 3);
        walk0DegFrames->append(QList<int>() << 2 << 3);

        Animation *walk0Deg = new Animation(spriteSheet, 32,32, walk0DegFrames, 250, true);

        movementAnims->append(walk0Deg);

        QList<QList<int>> *walk45DegFrames = new QList<QList<int>>();
        walk45DegFrames->append(QList<int>() << 1 << 0);
        walk45DegFrames->append(QList<int>() << 1 << 1);
        walk45DegFrames->append(QList<int>() << 1 << 2);
        walk45DegFrames->append(QList<int>() << 1 << 1);

        Animation *walk45Deg = new Animation(spriteSheet, 32,32, walk45DegFrames, 250, true);

        movementAnims->append(walk45Deg);

        QList<QList<int>> *walk90DegFrames = new QList<QList<int>>();
        walk90DegFrames->append(QList<int>() << 0 << 0);
        walk90DegFrames->append(QList<int>() << 0 << 1);
        walk90DegFrames->append(QList<int>() << 0 << 2);
        walk90DegFrames->append(QList<int>() << 0 << 1);

        Animation *walk90Deg = new Animation(spriteSheet, 32,32, walk90DegFrames, 250, true);

        movementAnims->append(walk90Deg);

        QList<QList<int>> *walk135DegFrames = new QList<QList<int>>();
        walk135DegFrames->append(QList<int>() << 13 << 0);
        walk135DegFrames->append(QList<int>() << 13 << 1);
        walk135DegFrames->append(QList<int>() << 13 << 2);
        walk135DegFrames->append(QList<int>() << 13 << 1);

        Animation *walk135Deg = new Animation(spriteSheetFlipped, 32,32, walk135DegFrames, 250, true);

        movementAnims->append(walk135Deg);

        QList<QList<int>> *walk180DegFrames = new QList<QList<int>>();
        walk180DegFrames->append(QList<int>() << 13 << 1);
        walk180DegFrames->append(QList<int>() << 12 << 1);
        walk180DegFrames->append(QList<int>() << 11 << 1);
        walk180DegFrames->append(QList<int>() << 12 << 1);

        Animation *walk180Deg = new Animation(spriteSheetFlipped, 32,32, walk180DegFrames, 250, true);

        movementAnims->append(walk180Deg);

        QList<QList<int>> *walk225DegFrames = new QList<QList<int>>();
        walk225DegFrames->append(QList<int>() << 11 << 0);
        walk225DegFrames->append(QList<int>() << 11 << 1);
        walk225DegFrames->append(QList<int>() << 11 << 2);
        walk225DegFrames->append(QList<int>() << 11 << 1);

        Animation *walk225Deg = new Animation(spriteSheetFlipped, 32,32, walk225DegFrames, 250, true);

        movementAnims->append(walk225Deg);

        QList<QList<int>> *walk270DegFrames = new QList<QList<int>>();
        walk270DegFrames->append(QList<int>() << 10 << 0);
        walk270DegFrames->append(QList<int>() << 10 << 1);
        walk270DegFrames->append(QList<int>() << 10 << 2);
        walk270DegFrames->append(QList<int>() << 10 << 1);

        Animation *walk270Deg = new Animation(spriteSheetFlipped, 32,32, walk270DegFrames, 250, true);

        movementAnims->append(walk270Deg);

        QList<QList<int>> *walk315DegFrames = new QList<QList<int>>();
        walk315DegFrames->append(QList<int>() << 3 << 0);
        walk315DegFrames->append(QList<int>() << 3 << 1);
        walk315DegFrames->append(QList<int>() << 3 << 2);
        walk315DegFrames->append(QList<int>() << 3 << 1);

        Animation *walk315Deg = new Animation(spriteSheet, 32,32, walk315DegFrames, 250, true);

        movementAnims->append(walk315Deg);

        miningAnims = new QList<Animation *>();

        QList<QList<int>> *mining0DegFrames = new QList<QList<int>>();
        mining0DegFrames->append(QList<int>() << 7 << 2);
        mining0DegFrames->append(QList<int>() << 7 << 0);
        mining0DegFrames->append(QList<int>() << 7 << 1);
        mining0DegFrames->append(QList<int>() << 7 << 0);

        Animation *mining0Deg = new Animation(spriteSheet, 32,32, mining0DegFrames, 250, true);

        miningAnims->append(mining0Deg);

        QList<QList<int>> *mining45DegFrames = new QList<QList<int>>();
        mining45DegFrames->append(QList<int>() << 6 << 1);
        mining45DegFrames->append(QList<int>() << 6 << 2);
        mining45DegFrames->append(QList<int>() << 6 << 3);
        mining45DegFrames->append(QList<int>() << 6 << 2);

        Animation *mining45Deg = new Animation(spriteSheet, 32,32, mining45DegFrames, 250, true);

        miningAnims->append(mining45Deg);

        QList<QList<int>> *mining90DegFrames = new QList<QList<int>>();
        mining90DegFrames->append(QList<int>() << 5 << 2);
        mining90DegFrames->append(QList<int>() << 5 << 1);
        mining90DegFrames->append(QList<int>() << 5 << 0);
        mining90DegFrames->append(QList<int>() << 5 << 1);

        Animation *mining90Deg = new Animation(spriteSheet, 32,32, mining90DegFrames, 250, true);

        miningAnims->append(mining90Deg);

        QList<QList<int>> *mining135DegFrames = new QList<QList<int>>();
        mining135DegFrames->append(QList<int>() << 8 << 3);
        mining135DegFrames->append(QList<int>() << 8 << 4);
        mining135DegFrames->append(QList<int>() << 8 << 3);

        Animation *mining135Deg = new Animation(spriteSheetFlipped, 32,32, mining135DegFrames, 250, true);

        miningAnims->append(mining135Deg);

        QList<QList<int>> *mining180DegFrames = new QList<QList<int>>();
        mining180DegFrames->append(QList<int>() << 7 << 3);
        mining180DegFrames->append(QList<int>() << 7 << 4);
        mining180DegFrames->append(QList<int>() << 7 << 3);

        Animation *mining180Deg = new Animation(spriteSheetFlipped, 32,32, mining180DegFrames, 250, true);

        miningAnims->append(mining180Deg);

        QList<QList<int>> *mining225DegFrames = new QList<QList<int>>();
        mining225DegFrames->append(QList<int>() << 6 << 3);
        mining225DegFrames->append(QList<int>() << 6 << 4);
        mining225DegFrames->append(QList<int>() << 6 << 3);

        Animation *mining225Deg = new Animation(spriteSheetFlipped, 32,32, mining225DegFrames, 250, true);

        miningAnims->append(mining225Deg);

        QList<QList<int>> *mining270DegFrames = new QList<QList<int>>();
        mining270DegFrames->append(QList<int>() << 5 << 3);
        mining270DegFrames->append(QList<int>() << 5 << 4);
        mining270DegFrames->append(QList<int>() << 5 << 3);

        Animation *mining270Deg = new Animation(spriteSheetFlipped, 32,32, mining270DegFrames, 250, true);

        miningAnims->append(mining270Deg);

        QList<QList<int>> *mining315DegFrames = new QList<QList<int>>();
        mining315DegFrames->append(QList<int>() << 8 << 2);
        mining315DegFrames->append(QList<int>() << 8 << 1);
        mining315DegFrames->append(QList<int>() << 8 << 2);

        Animation *mining315Deg = new Animation(spriteSheet, 32,32, mining315DegFrames, 250, true);

        miningAnims->append(mining315Deg);

        goldCarryAnims = new QList<Animation *>();

        QList<QList<int>> *goldCarry0DegFrames = new QList<QList<int>>();
        goldCarry0DegFrames->append(QList<int>() << 1 << 11);
        goldCarry0DegFrames->append(QList<int>() << 2 << 11);
        goldCarry0DegFrames->append(QList<int>() << 1 << 11);

        Animation *goldCarry0Deg = new Animation(spriteSheet, 32,32, goldCarry0DegFrames, 250, true);

        miningAnims->append(goldCarry0Deg);

        setCurrentAnimation(goldCarry0Deg);
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
