#include "humanlumbermill.h"


HumanLumberMill::HumanLumberMill(QPointF pos, bool finishedOnSpawn)  : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 3, QList<int>() << 2 << 3, BUILD_TIME, HP)
{

}

QRectF HumanLumberMill::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void HumanLumberMill::update()
{

}
