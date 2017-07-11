#include "humantownhall.h"

HumanTownHall::HumanTownHall(QPointF pos, bool finishedOnSpawn, ResourceManager *rm) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 2, QList<int>() << 2 << 2, BUILD_TIME, HP, rm)
{

}

QRectF HumanTownHall::boundingRect() const {
    return QRectF(0,0,96,96);
}
