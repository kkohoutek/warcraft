#include "Worker.hpp"
#include "entity/building/HumanFarm.hpp"
#include "entity/building/HumanBarracks.hpp"
#include "entity/building/HumanStables.hpp"
#include "entity/building/HumanTower.hpp"
#include "entity/building/HumanTownHall.hpp"
#include "entity/building/HumanChurch.hpp"
#include "entity/building/HumanBlacksmith.hpp"
#include "entity/building/HumanLumberMill.hpp"
#include <QGraphicsScene>
#include <QDebug>

#define MAX_WORKERS_PER_GOLDMINE    5
#define GOLD_PER_TRIP               10

Worker::Worker(QPointF pos, Unit::Type type, int *playerGold, int *playerLumber, ResourceManager *rm) : Unit(pos, type, 0.65f, 0, 0, 0) {
    this->playerGold   = playerGold;
    this->playerLumber = playerLumber;

    setMaxHP(40);
    setHP(40);

    switch(type){
        case PEASANT:
    {
        QPixmap *spriteSheet = rm->getSprite("PEASANT");
        QPixmap *spriteSheetFlipped = rm->getSprite("PEASANT_flipped");

        QList<QList<int>> walk0DegFrames;
        walk0DegFrames.append(QList<int>() << 1 << 3);
        walk0DegFrames.append(QList<int>() << 2 << 3);
        walk0DegFrames.append(QList<int>() << 3 << 3);
        walk0DegFrames.append(QList<int>() << 2 << 3);

        Animation *walk0Deg = new Animation(spriteSheet, 32,32, walk0DegFrames, 250, true);

        movementAnims.append(walk0Deg);

        QList<QList<int>> walk45DegFrames;
        walk45DegFrames.append(QList<int>() << 1 << 0);
        walk45DegFrames.append(QList<int>() << 1 << 1);
        walk45DegFrames.append(QList<int>() << 1 << 2);
        walk45DegFrames.append(QList<int>() << 1 << 1);

        Animation *walk45Deg = new Animation(spriteSheet, 32,32, walk45DegFrames, 250, true);

        movementAnims.append(walk45Deg);

        QList<QList<int>> walk90DegFrames;
        walk90DegFrames.append(QList<int>() << 0 << 0);
        walk90DegFrames.append(QList<int>() << 0 << 1);
        walk90DegFrames.append(QList<int>() << 0 << 2);
        walk90DegFrames.append(QList<int>() << 0 << 1);

        Animation *walk90Deg = new Animation(spriteSheet, 32,32, walk90DegFrames, 250, true);

        movementAnims.append(walk90Deg);

        QList<QList<int>> walk135DegFrames;
        walk135DegFrames.append(QList<int>() << 13 << 0);
        walk135DegFrames.append(QList<int>() << 13 << 1);
        walk135DegFrames.append(QList<int>() << 13 << 2);
        walk135DegFrames.append(QList<int>() << 13 << 1);

        Animation *walk135Deg = new Animation(spriteSheetFlipped, 32,32, walk135DegFrames, 250, true);

        movementAnims.append(walk135Deg);

        QList<QList<int>> walk180DegFrames;
        walk180DegFrames.append(QList<int>() << 13 << 1);
        walk180DegFrames.append(QList<int>() << 12 << 1);
        walk180DegFrames.append(QList<int>() << 11 << 1);
        walk180DegFrames.append(QList<int>() << 12 << 1);

        Animation *walk180Deg = new Animation(spriteSheetFlipped, 32,32, walk180DegFrames, 250, true);

        movementAnims.append(walk180Deg);

        QList<QList<int>> walk225DegFrames;
        walk225DegFrames.append(QList<int>() << 11 << 0);
        walk225DegFrames.append(QList<int>() << 11 << 1);
        walk225DegFrames.append(QList<int>() << 11 << 2);
        walk225DegFrames.append(QList<int>() << 11 << 1);

        Animation *walk225Deg = new Animation(spriteSheetFlipped, 32,32, walk225DegFrames, 250, true);

        movementAnims.append(walk225Deg);

        QList<QList<int>> walk270DegFrames;
        walk270DegFrames.append(QList<int>() << 10 << 0);
        walk270DegFrames.append(QList<int>() << 10 << 1);
        walk270DegFrames.append(QList<int>() << 10 << 2);
        walk270DegFrames.append(QList<int>() << 10 << 1);

        Animation *walk270Deg = new Animation(spriteSheetFlipped, 32,32, walk270DegFrames, 250, true);

        movementAnims.append(walk270Deg);

        QList<QList<int>> walk315DegFrames;
        walk315DegFrames.append(QList<int>() << 3 << 0);
        walk315DegFrames.append(QList<int>() << 3 << 1);
        walk315DegFrames.append(QList<int>() << 3 << 2);
        walk315DegFrames.append(QList<int>() << 3 << 1);

        Animation *walk315Deg = new Animation(spriteSheet, 32,32, walk315DegFrames, 250, true);

        movementAnims.append(walk315Deg);


        QList<QList<int>> mining0DegFrames;
        mining0DegFrames.append(QList<int>() << 7 << 2);
        mining0DegFrames.append(QList<int>() << 7 << 0);
        mining0DegFrames.append(QList<int>() << 7 << 1);
        mining0DegFrames.append(QList<int>() << 7 << 0);

        Animation *mining0Deg = new Animation(spriteSheet, 32,32, mining0DegFrames, 250, true);

        miningAnims.append(mining0Deg);

        QList<QList<int>> mining45DegFrames;
        mining45DegFrames.append(QList<int>() << 6 << 1);
        mining45DegFrames.append(QList<int>() << 6 << 2);
        mining45DegFrames.append(QList<int>() << 6 << 3);
        mining45DegFrames.append(QList<int>() << 6 << 2);

        Animation *mining45Deg = new Animation(spriteSheet, 32,32, mining45DegFrames, 250, true);

        miningAnims.append(mining45Deg);

        QList<QList<int>> mining90DegFrames;
        mining90DegFrames.append(QList<int>() << 5 << 2);
        mining90DegFrames.append(QList<int>() << 5 << 1);
        mining90DegFrames.append(QList<int>() << 5 << 0);
        mining90DegFrames.append(QList<int>() << 5 << 1);

        Animation *mining90Deg = new Animation(spriteSheet, 32,32, mining90DegFrames, 250, true);

        miningAnims.append(mining90Deg);

        QList<QList<int>> mining135DegFrames;
        mining135DegFrames.append(QList<int>() << 8 << 3);
        mining135DegFrames.append(QList<int>() << 8 << 4);
        mining135DegFrames.append(QList<int>() << 8 << 3);

        Animation *mining135Deg = new Animation(spriteSheetFlipped, 32,32, mining135DegFrames, 250, true);

        miningAnims.append(mining135Deg);

        QList<QList<int>> mining180DegFrames;
        mining180DegFrames.append(QList<int>() << 7 << 3);
        mining180DegFrames.append(QList<int>() << 7 << 4);
        mining180DegFrames.append(QList<int>() << 7 << 3);

        Animation *mining180Deg = new Animation(spriteSheetFlipped, 32,32, mining180DegFrames, 250, true);

        miningAnims.append(mining180Deg);

        QList<QList<int>> mining225DegFrames;
        mining225DegFrames.append(QList<int>() << 6 << 3);
        mining225DegFrames.append(QList<int>() << 6 << 4);
        mining225DegFrames.append(QList<int>() << 6 << 3);

        Animation *mining225Deg = new Animation(spriteSheetFlipped, 32,32, mining225DegFrames, 250, true);

        miningAnims.append(mining225Deg);

        QList<QList<int>> mining270DegFrames;
        mining270DegFrames.append(QList<int>() << 5 << 3);
        mining270DegFrames.append(QList<int>() << 5 << 4);
        mining270DegFrames.append(QList<int>() << 5 << 3);

        Animation *mining270Deg = new Animation(spriteSheetFlipped, 32,32, mining270DegFrames, 250, true);

        miningAnims.append(mining270Deg);

        QList<QList<int>> mining315DegFrames;
        mining315DegFrames.append(QList<int>() << 8 << 2);
        mining315DegFrames.append(QList<int>() << 8 << 1);
        mining315DegFrames.append(QList<int>() << 8 << 2);

        Animation *mining315Deg = new Animation(spriteSheet, 32,32, mining315DegFrames, 250, true);

        miningAnims.append(mining315Deg);

        QList<QList<int>> goldCarry0DegFrames;
        goldCarry0DegFrames.append(QList<int>() << 2 << 11);
        goldCarry0DegFrames.append(QList<int>() << 2 << 12);
        goldCarry0DegFrames.append(QList<int>() << 2 << 13);
        goldCarry0DegFrames.append(QList<int>() << 2 << 12);

        Animation *goldCarry0Deg = new Animation(spriteSheet, 32,32, goldCarry0DegFrames, 250, true);

        goldCarryAnims.append(goldCarry0Deg);

        //45deg chodi ak postihnuty
        QList<QList<int>> goldCarry45DegFrames;
        goldCarry45DegFrames.append(QList<int>() << 1 << 12);
        goldCarry45DegFrames.append(QList<int>() << 1 << 13);
        goldCarry45DegFrames.append(QList<int>() << 1 << 14);
        goldCarry45DegFrames.append(QList<int>() << 1 << 13);

        Animation *goldCarry45Deg = new Animation(spriteSheet, 32,32, goldCarry45DegFrames, 250, true);

        goldCarryAnims.append(goldCarry45Deg);

        QList<QList<int>> goldCarry90DegFrames;
        goldCarry90DegFrames.append(QList<int>() << 0 << 11);
        goldCarry90DegFrames.append(QList<int>() << 0 << 12);
        goldCarry90DegFrames.append(QList<int>() << 0 << 11);

        Animation *goldCarry90Deg = new Animation(spriteSheet, 32,32, goldCarry90DegFrames, 250, true);

        goldCarryAnims.append(goldCarry90Deg);

        QList<QList<int>> goldCarry135DegFrames;
        goldCarry135DegFrames.append(QList<int>() << 13 << 10);
        goldCarry135DegFrames.append(QList<int>() << 13 << 11);
        goldCarry135DegFrames.append(QList<int>() << 13 << 12);
        goldCarry135DegFrames.append(QList<int>() << 13 << 11);

        Animation *goldCarry135Deg = new Animation(spriteSheetFlipped, 32,32, goldCarry135DegFrames, 250, true);

        goldCarryAnims.append(goldCarry135Deg);

        QList<QList<int>> goldCarry180DegFrames;
        goldCarry180DegFrames.append(QList<int>() << 12 << 10);
        goldCarry180DegFrames.append(QList<int>() << 12 << 11);
        goldCarry180DegFrames.append(QList<int>() << 12 << 12);
        goldCarry180DegFrames.append(QList<int>() << 12 << 11);

        Animation *goldCarry180Deg = new Animation(spriteSheetFlipped, 32,32, goldCarry180DegFrames, 250, true);

        goldCarryAnims.append(goldCarry180Deg);

        QList<QList<int>> goldCarry225DegFrames;
        goldCarry225DegFrames.append(QList<int>() << 11 << 14);
        goldCarry225DegFrames.append(QList<int>() << 11 << 13);
        goldCarry225DegFrames.append(QList<int>() << 11 << 12);
        goldCarry225DegFrames.append(QList<int>() << 11 << 13);

        Animation *goldCarry225Deg = new Animation(spriteSheetFlipped, 32,32, goldCarry225DegFrames, 250, true);

        goldCarryAnims.append(goldCarry225Deg);

        QList<QList<int>> goldCarry270DegFrames;
        goldCarry270DegFrames.append(QList<int>() << 10 << 14);
        goldCarry270DegFrames.append(QList<int>() << 10 << 13);
        goldCarry270DegFrames.append(QList<int>() << 10 << 12);
        goldCarry270DegFrames.append(QList<int>() << 10 << 13);

        Animation *goldCarry270Deg = new Animation(spriteSheetFlipped, 32,32, goldCarry270DegFrames, 250, true);

        goldCarryAnims.append(goldCarry270Deg);

        QList<QList<int>> goldCarry315DegFrames;
        goldCarry315DegFrames.append(QList<int>() << 3 << 14);
        goldCarry315DegFrames.append(QList<int>() << 3 << 13);
        goldCarry315DegFrames.append(QList<int>() << 3 << 12);
        goldCarry315DegFrames.append(QList<int>() << 3 << 13);

        Animation *goldCarry315Deg = new Animation(spriteSheet, 32,32, goldCarry315DegFrames, 250, true);

        goldCarryAnims.append(goldCarry315Deg);


        QList<QList<int>> woodCarry0DegFrames;
        woodCarry0DegFrames.append(QList<int>() << 2 << 5);
        woodCarry0DegFrames.append(QList<int>() << 2 << 6);
        woodCarry0DegFrames.append(QList<int>() << 2 << 7);
        woodCarry0DegFrames.append(QList<int>() << 2 << 6);

        Animation *woodCarry0Deg = new Animation(spriteSheet, 32,32, woodCarry0DegFrames, 250, true);

        woodCarryAnims.append(woodCarry0Deg);

        QList<QList<int>> woodCarry45DegFrames;
        woodCarry45DegFrames.append(QList<int>() << 1 << 5);
        woodCarry45DegFrames.append(QList<int>() << 1 << 6);
        woodCarry45DegFrames.append(QList<int>() << 1 << 7);
        woodCarry45DegFrames.append(QList<int>() << 1 << 6);

        Animation *woodCarry45Deg = new Animation(spriteSheet, 32,32, woodCarry45DegFrames, 250, true);

        woodCarryAnims.append(woodCarry45Deg);

        QList<QList<int>> woodCarry90DegFrames;
        woodCarry90DegFrames.append(QList<int>() << 0 << 5);
        woodCarry90DegFrames.append(QList<int>() << 0 << 6);
        woodCarry90DegFrames.append(QList<int>() << 0 << 7);
        woodCarry90DegFrames.append(QList<int>() << 0 << 6);

        Animation *woodCarry90Deg = new Animation(spriteSheet, 32,32, woodCarry90DegFrames, 250, true);

        woodCarryAnims.append(woodCarry90Deg);

        QList<QList<int>> woodCarry135DegFrames;
        woodCarry135DegFrames.append(QList<int>() << 13 << 5);
        woodCarry135DegFrames.append(QList<int>() << 13 << 6);
        woodCarry135DegFrames.append(QList<int>() << 13 << 7);
        woodCarry135DegFrames.append(QList<int>() << 13 << 6);

        Animation *woodCarry135Deg = new Animation(spriteSheetFlipped, 32,32, woodCarry135DegFrames, 250, true);

        woodCarryAnims.append(woodCarry135Deg);

        QList<QList<int>> woodCarry180DegFrames;
        woodCarry180DegFrames.append(QList<int>() << 12 << 5);
        woodCarry180DegFrames.append(QList<int>() << 12 << 6);
        woodCarry180DegFrames.append(QList<int>() << 12 << 7);
        woodCarry180DegFrames.append(QList<int>() << 12 << 6);

        Animation *woodCarry180Deg = new Animation(spriteSheetFlipped, 32,32, woodCarry180DegFrames, 250, true);

        woodCarryAnims.append(woodCarry180Deg);

        QList<QList<int>> woodCarry225DegFrames;
        woodCarry225DegFrames.append(QList<int>() << 11 << 5);
        woodCarry225DegFrames.append(QList<int>() << 11 << 6);
        woodCarry225DegFrames.append(QList<int>() << 11 << 7);
        woodCarry225DegFrames.append(QList<int>() << 11 << 6);

        Animation *woodCarry225Deg = new Animation(spriteSheetFlipped, 32,32, woodCarry225DegFrames, 250, true);

        woodCarryAnims.append(woodCarry225Deg);

        QList<QList<int>> woodCarry270DegFrames;
        woodCarry270DegFrames.append(QList<int>() << 10 << 5);
        woodCarry270DegFrames.append(QList<int>() << 10 << 6);
        woodCarry270DegFrames.append(QList<int>() << 10 << 7);
        woodCarry270DegFrames.append(QList<int>() << 10 << 6);

        Animation *woodCarry270Deg = new Animation(spriteSheetFlipped, 32,32, woodCarry270DegFrames, 250, true);

        woodCarryAnims.append(woodCarry270Deg);

        QList<QList<int>> woodCarry315DegFrames;
        woodCarry315DegFrames.append(QList<int>() << 3 << 5);
        woodCarry315DegFrames.append(QList<int>() << 3 << 6);
        woodCarry315DegFrames.append(QList<int>() << 3 << 7);
        woodCarry315DegFrames.append(QList<int>() << 3 << 6);

        Animation *woodCarry315Deg = new Animation(spriteSheet, 32,32, woodCarry315DegFrames, 250, true);

        woodCarryAnims.append(woodCarry315Deg);

        QList<QList<int>> deathFrames;
        deathFrames.append(QList<int>() << 12 << 0);
        deathFrames.append(QList<int>() << 12 << 1);
        deathFrames.append(QList<int>() << 12 << 2);

        Animation *death = new Animation(spriteSheet, 32,32, deathFrames, 250, false);

        deathAnims.append(death);

        setCurrentAnimation(walk90Deg);

        break;
    }

        case PEON:
        //peon
        break;

    default:
        qFatal("Incorrect UnitType!");
    }
}

Worker::~Worker() {
    // Pro bezpečnost
    delete mineCommand;
    delete buildCommand;
    delete harvestCommand;
}

QRectF Worker::boundingRect() const {
    return QRectF(16,16,32,32);
}

void Worker::cancel() {
    Unit::cancel();
    delete mineCommand;
    delete buildCommand;
    delete harvestCommand;
    mineCommand = nullptr;
    buildCommand = nullptr;
    harvestCommand = nullptr;
}

bool Worker::canSelect() const {
    return Entity::canSelect() && buildCommand == nullptr;
}

void Worker::mine(Goldmine *source, Building *dest){
    cancel();
    mineCommand = new MineCommand(source, dest);
    goTo(source->center());
}

void Worker::harvest(Trees *source, Building *dest){
    cancel();
    harvestCommand = new HarvestCommand(source, dest);
    goTo(source->center());
}

void Worker::build(Building *building) {
    if(buildCommand) return;
    cancel();
    buildCommand = new BuildCommand(building);
    scene()->addItem(building);
    building->setOpacity(0.5);
    building->setHighlighted(false);
    goTo(building->center());
}

void Worker::update(){
    Unit::update();

    if(buildCommand){
        if(!buildCommand->what->isBuildingFinished()){
                    if(collidesWithItem(buildCommand->what)){
                        stopMoving();
                        path.clear();
                        buildCommand->what->setOpacity(1);
                        hide();
                        buildCommand->what->startConstruction();
                    } else if(path.isEmpty()){
                        path.clear();
                        setTarget(buildCommand->what->center()); // musíme zajistit, že worker bude kolidovat s budovou
                        move();
                    }
        } else {
            this->show();
            //setPos((*(graph->gimmeNode(buildCommand->what->center(),true)))->pos);
            cancel();
        }
    } else if (mineCommand){
        if(currentAnimationSet == &movementAnims && collidesWithItem(mineCommand->source)){
            if(mineCommand->source->isAlive()){
                mineCommand->source->damage(GOLD_PER_TRIP);
                stopMoving();
                setTarget(mineCommand->dest->center());
                //setPath(bfs::shortestPath(*graph, center(), mineCommand->dest->center())); // anims broken
                move();
                currentAnimationSet = &goldCarryAnims;
            } else {
                stopMoving();
                cancel();
            }
        } else if (currentAnimationSet == &goldCarryAnims && collidesWithItem(mineCommand->dest)){
            *playerGold += GOLD_PER_TRIP;
            stopMoving();
            setTarget(mineCommand->source->center());
            //setPath(bfs::shortestPath(*graph, center(), mineCommand->source->center())); // anims broken
            move();
            currentAnimationSet = &movementAnims;
        }
    }
}

void Worker::updateAnimation() {
    if(mineCommand && targetPoint == mineCommand->dest->center()){
        currentAnimationSet = &goldCarryAnims;
    } else {
        currentAnimationSet = &movementAnims;
    }
    Unit::updateAnimation();
}

