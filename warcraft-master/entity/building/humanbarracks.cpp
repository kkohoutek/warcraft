#include "humanbarracks.h"

HumanBarracks::HumanBarracks(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 1 << 2, QList<int>() << 0 << 2, BUILD_TIME, HP)
{

}

QRectF HumanBarracks::boundingRect() const {
    return QRectF(0,0,48,48);
}

void HumanBarracks::update()
{

}
