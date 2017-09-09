#include "humanfarm.h"

HumanFarm::HumanFarm(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, int &playerFood) : Building(pos, H_FARM, finishedOnSpawn, HUMAN, QList<int>() << 1 << 1, QList<int>() << 0 << 1, BUILD_TIME, HP, rm) {
    this->playerFood = &playerFood;
}

QRectF HumanFarm::boundingRect() const
{
    return QRectF(8,8,78,76);
}

void HumanFarm::update() {
    if(isBuildingFinished() && !foodIncreased){
        *playerFood += 4;
        foodIncreased = true;
    }
}

