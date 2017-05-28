#include "humantower.h"

HumanTower::HumanTower(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 1, QList<int>() << 2 << 1, 48, 48, BUILD_TIME, HP)
{

}

void HumanTower::update()
{

}
