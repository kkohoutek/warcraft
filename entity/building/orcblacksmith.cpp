#include "orcblacksmith.h"

OrcBlacksmith::OrcBlacksmith(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn,ORC, QList<int>() << 3 << 0, QList<int>() << 2 << 0, BUILD_TIME, HP)
{

}

QRectF OrcBlacksmith::boundingRect() const
{
    return QRectF(6,6,36,36);
}

void OrcBlacksmith::update()
{

}
