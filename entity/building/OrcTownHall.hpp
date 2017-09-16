#ifndef ORCTOWNHALL_HPP
#define ORCTOWNHALL_HPP

#include "Building.hpp"

class OrcTownHall : public Building
{
public:
    static const int COST_GOLD = 400;
    static const int COST_LUMBER = 400;
    static const int HP = 2500;
    static const int BUILD_TIME = (1000*1000)/100;

    OrcTownHall(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // ORCTOWNHALL_HPP
