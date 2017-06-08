#include "orctownhall.h"

OrcTownHall::OrcTownHall(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn, ORC, QList<int>() << 1 << 2,
             QList<int>() << 0 << 2, BUILD_TIME, HP)
{

}
QRectF OrcTownHall::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void OrcTownHall::update()
{

}
