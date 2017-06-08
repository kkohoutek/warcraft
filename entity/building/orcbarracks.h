#ifndef ORCBARRACKS_H
#define ORCBARRACKS_H

#include "building.h"

class OrcBarracks : public Building
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 500;
    static const int HP = 800;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    OrcBarracks(QPointF pos, bool finishedOnSpawn);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
    void update() override;

};

#endif // ORCBARRACKS_H
