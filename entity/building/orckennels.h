#ifndef ORCKENNELS_H
#define ORCKENNELS_H
#include "building.h"


class OrcKennels : public Building
{
public:
    static const int COST_GOLD = 1000;
    static const int COST_LUMBER = 400;
    static const int HP = 500;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    OrcKennels(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
    void update() override;
};

#endif // ORCKENNELS_H
