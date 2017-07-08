#ifndef ORCTOWNHALL_H
#define ORCTOWNHALL_H

#include "building.h"

class OrcTownHall : public Building
{
public:
    static const int COST_GOLD = 400;
    static const int COST_LUMBER = 400;
    static const int HP = 2500;
    static const int BUILD_TIME = (1000*1000)/TIME_DIVISOR;

    OrcTownHall(QPointF pos, bool finishedOnSpawn, Resources &res);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

    void update() override;
};

#endif // ORCTOWNHALL_H
