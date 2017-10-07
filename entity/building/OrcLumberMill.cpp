#include "OrcLumberMill.hpp"

OrcLumberMill::OrcLumberMill(QPointF pos, bool finishedOnSpawn, ResourceManager*rm) :
    Building(pos, O_LUMBERMILL, finishedOnSpawn,ORC,QList<int>() << 0 << 3, QList<int>() << 4 << 2, BUILD_TIME, HP, rm)
{

}

QRectF OrcLumberMill::boundingRect() const {
    return QRectF(0,0,98,98);
}
