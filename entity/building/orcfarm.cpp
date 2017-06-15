#include "orcfarm.h"

OrcFarm::OrcFarm(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn,ORC, QList<int>() << 0 << 1, QList<int>() << 4 << 0, BUILD_TIME, HP)
{

}

QRectF OrcFarm::boundingRect() const
{
    return QRectF(6,6,78,78);
}

void OrcFarm::update()
{

}
