#ifndef HUMANSTABLES_H
#define HUMANSTABLES_H

#include "building.h"
class HumanStables : public Building
{
public:
    static const int COST_GOLD = 1000;
    static const int COST_LUMBER = 400;
    static const int HP = 500;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    HumanStables(QPointF pos, bool finishedOnSpawn, Resources &res);
    QRectF boundingRect() const override;

};

#endif // HUMANSTABLES_H
