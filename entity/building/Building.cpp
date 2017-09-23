#include "Building.hpp"

Building::Building(QPointF pos, Building::Type type, bool finishedOnSpawn, Race race, QList<int> preFrame, QList<int> endFrame, int buildTime, int maxHP, ResourceManager *rm) : Entity(pos)
{
    setMaxHP(maxHP);
    this->buildTime = buildTime;
    this->type = type;

    QPixmap *spriteSheet = nullptr;
    switch(race){
    case HUMAN:
        spriteSheet = rm->getSprite("BUILDINGS_H");
        break;
    case ORC:
        spriteSheet = rm->getSprite("BUILDINGS_O");
        break;
    }

    QList<QList<int>> frames;
    frames.append(QList<int>() << 0 << 0);
    frames.append(QList<int>() << 1 << 0);
    frames.append(preFrame);
    frames.append(endFrame);

    Animation *buildAnimation = new Animation(spriteSheet, 48, 48, frames, buildTime/frames.size(), false);
    setCurrentAnimation(buildAnimation);

    if(finishedOnSpawn){
        finished = true;
        setHP(maxHP);
        buildAnimation->setCurrentFrame(3);
    } else {
        setHP(0);
        finished = false;
        buildTimer = new QTimer();
        buildTimer->setInterval(buildTime/maxHP);
        connect(buildTimer, SIGNAL(timeout()), this, SLOT(constructionUpdate()));
    }

    scaleX = 2;
    scaleY = 2;

    setZValue(-1);

}

Building::~Building() {
    delete buildTimer;
}

void Building::startConstruction() {
    getCurrentAnimation()->start();
    if(!buildTimer->isActive()){
        buildTimer->start();
    }
}

void Building::constructionUpdate() {
    if(getHP() + 1 < getMaxHP()){
        setHP(getHP()+1);
    } else {
        buildTimer->stop();
        delete buildTimer;
        buildTimer = nullptr;
        finished = true;
    }
}

