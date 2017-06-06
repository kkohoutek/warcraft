#include "humantownhall.h"

HumanTownHall::HumanTownHall(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 2, QList<int>() << 2 << 2, BUILD_TIME, HP)
{

}

QRectF HumanTownHall::boundingRect() const {
    return QRectF(0,0,48,48);
}
