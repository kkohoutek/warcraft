#include "HumanLumberMill.hpp"


HumanLumberMill::HumanLumberMill(QPointF pos, bool finishedOnSpawn, ResourceManager *rm)  : Building(pos, H_LUMBERMILL, finishedOnSpawn, HUMAN, QList<int>() << 3 << 3, QList<int>() << 2 << 3, BUILD_TIME, HP, rm)
{

}

QRectF HumanLumberMill::boundingRect() const
{
    return QRectF(0,0,96,96);
}
