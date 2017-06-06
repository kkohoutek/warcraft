#include "humanchurch.h"

HumanChurch::HumanChurch(QPointF pos, bool finishedOnSpawn): Building(pos, finishedOnSpawn, HUMAN, QList<int>() << 1 << 3, QList<int>() << 0 << 3, BUILD_TIME, HP)
{

}

QRectF HumanChurch::boundingRect() const {
    return QRectF(0,0,48,48);
}
