#include "humanfarm.h"

HumanFarm::HumanFarm(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 1 << 1, QList<int>() << 0 << 1, BUILD_TIME, HP) {

}

QRectF HumanFarm::boundingRect() const
{
    return QRectF(8,8,78,76);
}

