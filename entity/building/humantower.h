#ifndef HUMANTOWER_H
#define HUMANTOWER_H

#include "building.h"
class HumanTower : public Building
{
public:
    static const int COST_GOLD = 1400;
    static const int COST_LUMBER = 300;
    static const int HP = 900;
    static const int BUILD_TIME = (2000*1000)/TIME_DIVISOR;

    HumanTower(QPointF pos, bool finishedOnSpawn, Resources &res);
    QRectF boundingRect() const override;
};

#endif // HUMANTOWER_H
