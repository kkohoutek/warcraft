#ifndef HUMANCHURCH_H
#define HUMANCHURCH_H

#include "building.h"
class HumanChurch : public Building
{
public:
    static const int COST_GOLD = 800;
    static const int COST_LUMBER = 500;
    static const int HP = 700;
    static const int BUILD_TIME = (2000*1000)/TIME_DIVISOR;
    HumanChurch(QPointF pos, bool finishedOnSpawn);

    QRectF boundingRect() const override;
};

#endif // HUMANCHURCH_H
