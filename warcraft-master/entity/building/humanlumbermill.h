#ifndef HUMANLUMBERMILL_H
#define HUMANLUMBERMILL_H

#include "building.h"
class HumanLumberMill : public Building
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 500;
    static const int HP = 600;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;
    HumanLumberMill(QPointF pos, bool finishedOnSpawn);

    QRectF boundingRect() const override;
    void update() override;
};

#endif // HUMANLUMBERMILL_H
