#include "humantower.h"

HumanTower::HumanTower(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 1, QList<int>() << 2 << 1, BUILD_TIME, HP)
{

}

QRectF HumanTower::boundingRect() const {
    return QRectF(6,6,36,36);
}
