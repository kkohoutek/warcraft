#ifndef ORCBLACKSSMITH_H
#define ORCBLACKSSMITH_H
#include "building.h"


class OrcBlacksSmith : public Building
{
public:
    static const int COST_GOLD = 900;
    static const int COST_LUMBER = 400;
    static const int HP = 800;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    OrcBlacksSmith(QPointF pos, bool finishedOnSpawn);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
    void update() override;
};

#endif // ORCBLACKSSMITH_H
