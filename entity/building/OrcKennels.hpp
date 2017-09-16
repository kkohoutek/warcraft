#ifndef ORCKENNELS_HPP
#define ORCKENNELS_HPP
#include "Building.hpp"


class OrcKennels : public Building
{
public:
    static const int COST_GOLD = 1000;
    static const int COST_LUMBER = 400;
    static const int HP = 500;
    static const int BUILD_TIME = (1500*1000)/100;

    OrcKennels(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
};

#endif // ORCKENNELS_HPP
