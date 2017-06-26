#include "building.h"
#include <QDebug>

Building::Building(QPointF pos, bool finishedOnSpawn, Race race, QList<int> preFrame, QList<int> endFrame, int buildTime, int maxHP) : Entity(pos)
{
    setMaxHP(maxHP);
    this->buildTime = buildTime;

    QPixmap *spriteSheet;
    switch(race){
    case HUMAN:
        spriteSheet = new QPixmap(":/graphics/BUILDINGS_H");
        break;
    case ORC:
        spriteSheet = new QPixmap(":/graphics/BUILDINGS_O");
        break;
    }

    QList<QList<int>> *frames = new QList<QList<int>>();
    frames->append(QList<int>() << 0 << 0);
    frames->append(QList<int>() << 1 << 0);
    frames->append(preFrame);
    frames->append(endFrame);

    buildAnimation = new Animation(spriteSheet, 48, 48, frames, buildTime/frames->size(), false);
    setCurrentAnimation(buildAnimation);
    buildAnimation->stop();

    if(finishedOnSpawn){
        finished = true;
        buildTimer = NULL;
        setHP(maxHP);
        buildAnimation->setCurrentFrame(3);
        buildAnimation->stop();
    } else {
        setHP(0);
        finished = false;
        buildTimer = new QTimer();
        buildTimer->setInterval(buildTime/maxHP);
        connect(buildTimer, &QTimer::timeout, this, &constructionUpdate);
    }

    scaleX = 2;
    scaleY = 2;

}

Building::~Building()
{
    delete buildTimer;
    delete buildAnimation->getSpriteSheet();
}

void Building::update(){

}

void Building::beginConstruction(){
    if(buildTimer->isActive()) return;
    buildTimer->start();
    buildAnimation->start();
}

bool Building::isBuildingFinished() const {
    return finished;
}


void Building::constructionUpdate()
{
    if(getHP() + 1 < getMaxHP()){
        setHP(getHP()+1);
    } else {
        buildTimer->stop();
        finished = true;
    }
}
