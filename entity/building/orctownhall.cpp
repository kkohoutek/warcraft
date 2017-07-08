#include "orctownhall.h"

OrcTownHall::OrcTownHall(QPointF pos, bool finishedOnSpawn, Resources &res) :
    Building(pos, finishedOnSpawn, ORC, QList<int>() << 1 << 2,
             QList<int>() << 0 << 2, BUILD_TIME, HP, res)
{

}
QRectF OrcTownHall::boundingRect() const
{
    return QRectF(0,0,96,96);
}

void OrcTownHall::update()
{

}
