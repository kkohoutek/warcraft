#include "humanblacksmith.h"

HumanBlacksmith::HumanBlacksmith(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 0, QList<int>() << 2 << 0, 48, 48, BUILD_TIME, HP)
{

}

void HumanBlacksmith::update()
{

}
