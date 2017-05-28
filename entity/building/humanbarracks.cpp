#include "humanbarracks.h"

HumanBarracks::HumanBarracks(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 1 << 2, QList<int>() << 0 << 2, 48, 48, BUILD_TIME, HP)
{

}

void HumanBarracks::update()
{

}
