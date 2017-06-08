#include "orclumbermill.h"

OrcLumberMill::OrcLumberMill(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn,ORC,QList<int>() << 0 << 3, QList<int>() << 4 << 2, BUILD_TIME, HP)
{

}

QRectF OrcLumberMill::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void OrcLumberMill::update()
{

}