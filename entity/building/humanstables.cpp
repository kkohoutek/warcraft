#include "humanstables.h"

HumanStables::HumanStables(QPointF pos, bool finishedOnSpawn, Resources &res) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 1 << 4, QList<int>() << 0 << 4, BUILD_TIME, HP, res)
{

}

QRectF HumanStables::boundingRect() const {
    return QRectF(0,0,98,96);
}
