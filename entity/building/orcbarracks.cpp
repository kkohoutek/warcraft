#include "orcbarracks.h"

OrcBarracks::OrcBarracks(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn,ORC,QList<int>() << 4 << 1, QList<int>() << 3 << 1, BUILD_TIME, HP)
{

}

QRectF OrcBarracks::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void OrcBarracks::update()
{

}
