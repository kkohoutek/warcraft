#include "humanlumbermill.h"


HumanLumberMill::HumanLumberMill(QPointF pos, bool finishedOnSpawn)  : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 3, QList<int>() << 2 << 3, 48, 48, BUILD_TIME, HP)
{

}

void HumanLumberMill::update()
{

}
