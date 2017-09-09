#include "humanchurch.h"

HumanChurch::HumanChurch(QPointF pos, bool finishedOnSpawn, ResourceManager *rm):
    Building(pos, H_CHURCH, finishedOnSpawn, HUMAN, QList<int>() << 1 << 3, QList<int>() << 0 << 3, BUILD_TIME, HP, rm)
{
}

QRectF HumanChurch::boundingRect() const {
    return QRectF(0,0,96,96);
}
