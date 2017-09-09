#include "humanblacksmith.h"

HumanBlacksmith::HumanBlacksmith(QPointF pos, bool finishedOnSpawn, ResourceManager *rm) : Building(pos, H_BLACKSMITH, finishedOnSpawn, HUMAN, QList<int>() << 3 << 0, QList<int>() << 2 << 0, BUILD_TIME, HP, rm)
{

}

QRectF HumanBlacksmith::boundingRect() const {
    return QRectF(6,6,78,78);
}
