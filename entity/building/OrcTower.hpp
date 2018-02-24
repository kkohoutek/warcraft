#ifndef ORCTOWER_HPP
#define ORCTOWER_HPP
#include "Building.hpp"


class OrcTower : public Building
{
public:
    static const int COST_GOLD = 1400;
    static const int COST_LUMBER = 0;
    static const int HP = 900;
    static const int BUILD_TIME = (2000*1000)/100;

    OrcTower(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
};

#endif // ORCTOWER_HPP
