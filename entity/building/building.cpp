#include "building.h"


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

    if(finishedOnSpawn){
        buildTimer = NULL;
        setHP(maxHP);
        buildAnimation->setCurrentFrame(3);
        buildAnimation->stop();
    } else {
        buildTimer = new QTimer();
        buildTimer->start(buildTime/maxHP);
        connect(buildTimer, &QTimer::timeout, this, &constructionUpdate);
    }


}

Building::~Building()
{
    delete buildTimer;
    delete buildAnimation;
}

void Building::update(){

}

bool Building::isBuildingFinished()
{
    return buildTimer == NULL || !buildTimer->isActive();
}


void Building::constructionUpdate()
{
    if(getHP() + 1 < getMaxHP()){
        setHP(getHP()+1);
    } else {
        buildTimer->stop();
    }
}
