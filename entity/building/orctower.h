#ifndef ORCTOWER_H
#define ORCTOWER_H
#include "building.h"


class OrcTower : public Building
{
public:
    static const int COST_GOLD = 1400;
    static const int COST_LUMBER = 300;
    static const int HP = 900;
    static const int BUILD_TIME = (2000*1000)/TIME_DIVISOR;

    OrcTower(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
    void update() override;
};

#endif // ORCTOWER_H
