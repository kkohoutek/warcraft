#ifndef ORCFARM_HPP
#define ORCFARM_HPP

#include "Building.hpp"

class OrcFarm : public Building
{
public:
    static const int COST_GOLD = 500;
    static const int COST_LUMBER = 300;
    static const int HP = 400;
    static const int BUILD_TIME = (1000*1000)/100;

    OrcFarm(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

};

#endif // ORCFARM_HPP
