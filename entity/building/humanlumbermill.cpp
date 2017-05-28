#include "humanlumbermill.h"


HumanLumberMill::HumanLumberMill(QPointF pos, bool finishedOnSpawn)  : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 1 << 1, QList<int>() << 0 << 1, 48, 48, BUILD_TIME, HP)
{

}

void HumanLumberMill::update()
{

}
