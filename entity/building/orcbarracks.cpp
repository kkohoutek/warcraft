#include "orcbarracks.h"

OrcBarracks::OrcBarracks(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn,ORC,QList<int>() << 4 << 1, QList<int>() << 3 << 1, BUILD_TIME, HP)
{

}

QRectF OrcBarracks::boundingRect() const
{
    return QRectF(-2,-2,100,100);
}

void OrcBarracks::update()
{

}
