#include "orcblacksmith.h"

OrcBlacksmith::OrcBlacksmith(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn,ORC, QList<int>() << 3 << 0, QList<int>() << 2 << 0, BUILD_TIME, HP)
{

}

QRectF OrcBlacksmith::boundingRect() const
{
    return QRectF(4,4,82,82);
}

void OrcBlacksmith::update()
{

}
