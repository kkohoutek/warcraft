#ifndef HUMANBARRACKS_H
#define HUMANBARRACKS_H

#include "building.h"
class HumanBarracks : public Building
{
public:
    static const int COST_GOLD = 400;
    static const int COST_LUMBER = 400;
    static const int HP = 2500;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    HumanBarracks(QPointF pos, bool finishedOnSpawn);
    QRectF boundingRect() const override;
};

#endif // HUMANBARRACKS_H
