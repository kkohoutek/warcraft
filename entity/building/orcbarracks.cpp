#include "orcbarracks.h"

OrcBarracks::OrcBarracks(QPointF pos, bool finishedOnSpawn, ResourceManager *rm) :
    Building(pos, O_BARRACKS, finishedOnSpawn,ORC,QList<int>() << 4 << 1, QList<int>() << 3 << 1, BUILD_TIME, HP, rm)
{

}

QRectF OrcBarracks::boundingRect() const
{
    return QRectF(-2,-2,100,100);
}

void OrcBarracks::update()
{

}
