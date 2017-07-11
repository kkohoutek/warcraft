#ifndef HUMANTOWNHALL_H
#define HUMANTOWNHALL_H

#include "building.h"

class HumanTownHall : public Building
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 500;
    static const int HP = 800;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    HumanTownHall(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

};

#endif // HUMANTOWNHALL_H
