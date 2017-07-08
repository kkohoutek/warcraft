#include "humanblacksmith.h"

HumanBlacksmith::HumanBlacksmith(QPointF pos, bool finishedOnSpawn, Resources &res) : Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 3 << 0, QList<int>() << 2 << 0, BUILD_TIME, HP, res)
{

}

QRectF HumanBlacksmith::boundingRect() const {
    return QRectF(6,6,78,78);
}
