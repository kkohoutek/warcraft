#include "humanfarm.h"

HumanFarm::HumanFarm(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 1 << 1, QList<int>() << 0 << 1, 48, 48, BUILD_TIME, HP)
{

}

void HumanFarm::update()
{

}

QRectF HumanFarm::boundingRect() const
{
    return QRectF(6,6,36,36);
}

