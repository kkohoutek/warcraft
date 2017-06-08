#include "orctower.h"

OrcTower::OrcTower(QPointF pos, bool finishedOnSpawn):
    Building(pos,finishedOnSpawn, ORC, QList<int>() << 2 << 1, QList<int>() << 1 << 1,BUILD_TIME, HP)
{

}

QRectF OrcTower::boundingRect() const
{
    return QRectF(6,6,36,36);
}

void OrcTower::update()
{

}
