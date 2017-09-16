#include "HumanStables.hpp"

HumanStables::HumanStables(QPointF pos, bool finishedOnSpawn, ResourceManager *rm) : Building(pos, H_STABLES, finishedOnSpawn, HUMAN, QList<int>() << 1 << 4, QList<int>() << 0 << 4, BUILD_TIME, HP, rm)
{

}

QRectF HumanStables::boundingRect() const {
    return QRectF(0,0,98,96);
}
