#include "humantower.h"

HumanTower::HumanTower(QPointF pos, bool finishedOnSpawn, ResourceManager *rm) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 1, QList<int>() << 2 << 1, BUILD_TIME, HP, rm)
{

}

QRectF HumanTower::boundingRect() const {
    return QRectF(13,8,71,78);
}
