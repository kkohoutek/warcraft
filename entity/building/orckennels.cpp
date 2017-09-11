#include "orckennels.h"

OrcKennels::OrcKennels(QPointF pos, bool finishedOnSpawn, ResourceManager*rm) :
    Building(pos, O_KENNELS, finishedOnSpawn, ORC,QList<int>() << 2 << 3, QList<int>() << 1 << 3, BUILD_TIME, HP, rm)
{

}

QRectF OrcKennels::boundingRect() const
{
    return QRectF(0,0,98,98);
}
