#include "Building.hpp"
#include <QDebug>

Building::Building(QPointF pos, Building::Type type, bool finishedOnSpawn, Race race, const QList<int> &preFrame, const QList<int> &endFrame, int buildTime, int maxHP, ResourceManager *rm) : Entity(pos)
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
    buildAnimation->setCurrentFrame(3);
    setCurrentAnimation(buildAnimation);

    if(finishedOnSpawn){
        finished = true;
        setHP(maxHP);
    } else {
        setHP(0);
        finished = false;
    }

    scaleX = 2;
    scaleY = 2;

    setZValue(-1);

}

Building::~Building() {
    delete buildTimer;
}

void Building::startConstruction() {
    if(buildTimer) return;

    buildTimer = new QTimer();
    buildTimer->setInterval(buildTime/getMaxHP());
    qDebug() << "Interval" << buildTime/getMaxHP();
    connect(buildTimer, SIGNAL(timeout()), this, SLOT(constructionUpdate()));
    buildTimer->start();

    getCurrentAnimation()->setCurrentFrame(0);
    getCurrentAnimation()->start();
}

void Building::die() {
    getCurrentAnimation()->setCurrentFrame(0);
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

