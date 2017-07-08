#include "humantownhall.h"

HumanTownHall::HumanTownHall(QPointF pos, bool finishedOnSpawn, Resources &res) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 2, QList<int>() << 2 << 2, BUILD_TIME, HP, res)
{

}

QRectF HumanTownHall::boundingRect() const {
    return QRectF(0,0,96,96);
}
