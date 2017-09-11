#ifndef ORCFARM_H
#define ORCFARM_H

#include "building.h"

class OrcFarm : public Building
{
public:
    static const int COST_GOLD = 500;
    static const int COST_LUMBER = 300;
    static const int HP = 400;
    static const int BUILD_TIME = (1000*1000)/TIME_DIVISOR;

    OrcFarm(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

};

#endif // ORCFARM_H
