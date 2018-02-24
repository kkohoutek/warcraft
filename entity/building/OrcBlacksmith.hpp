#ifndef ORCBLACKSMITH_HPP
#define ORCBLACKSMITH_HPP
#include "Building.hpp"


class OrcBlacksmith : public Building
{
public:
    static const int COST_GOLD = 900;
    static const int COST_LUMBER = 0;
    static const int HP = 800;
    static const int BUILD_TIME = (1500*1000)/100;

    OrcBlacksmith(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
};

#endif // ORCBLACKSMITH_HPP
