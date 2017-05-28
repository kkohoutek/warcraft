#include "humantownhall.h"

HumanTownHall::HumanTownHall(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 2, QList<int>() << 2 << 2, 48, 48, BUILD_TIME, HP)
{

}

void HumanTownHall::update()
{

}
