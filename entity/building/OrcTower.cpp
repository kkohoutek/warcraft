#include "OrcTower.hpp"

OrcTower::OrcTower(QPointF pos, bool finishedOnSpawn, ResourceManager*rm):
    Building(pos,O_TOWER,finishedOnSpawn, ORC, QList<int>() << 2 << 1, QList<int>() << 1 << 1,BUILD_TIME, HP, rm)
{

}

QRectF OrcTower::boundingRect() const {
    return QRectF(6,6,84,84);
}
