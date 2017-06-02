#include "humanblacksmith.h"

HumanBlacksmith::HumanBlacksmith(QPointF pos, bool finishedOnSpawn) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 0, QList<int>() << 2 << 0, BUILD_TIME, HP)
{

}

QRectF HumanBlacksmith::boundingRect() const {
    return QRectF(6,6,36,36);
}

void HumanBlacksmith::update()
{

}
