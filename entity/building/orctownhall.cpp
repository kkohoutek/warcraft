#include "orctownhall.h"

OrcTownHall::OrcTownHall(QPointF pos, bool finishedOnSpawn, ResourceManager *rm) :
    Building(pos, O_TOWNHALL, finishedOnSpawn, ORC, QList<int>() << 1 << 2,
             QList<int>() << 0 << 2, BUILD_TIME, HP, rm)
{

}
QRectF OrcTownHall::boundingRect() const
{
    return QRectF(0,0,96,96);
}

void OrcTownHall::update()
{

}
