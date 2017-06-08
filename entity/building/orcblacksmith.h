#ifndef ORCBLACKSMITH_H
#define ORCBLACKSMITH_H
#include "building.h"


class OrcBlacksmith : public Building
{
public:
    static const int COST_GOLD = 900;
    static const int COST_LUMBER = 400;
    static const int HP = 800;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    OrcBlacksmith(QPointF pos, bool finishedOnSpawn);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
    void update() override;
};

#endif // ORCBLACKSMITH_H
