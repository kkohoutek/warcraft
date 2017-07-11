#include "orclumbermill.h"

OrcLumberMill::OrcLumberMill(QPointF pos, bool finishedOnSpawn, ResourceManager*rm) :
    Building(pos, finishedOnSpawn,ORC,QList<int>() << 0 << 3, QList<int>() << 4 << 2, BUILD_TIME, HP, rm)
{

}

QRectF OrcLumberMill::boundingRect() const
{
    return QRectF(0,0,98,98);
}

void OrcLumberMill::update()
{

}
