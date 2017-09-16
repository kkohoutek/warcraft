#ifndef ORCBARRACKS_HPP
#define ORCBARRACKS_HPP

#include "Building.hpp"

class OrcBarracks : public Building
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 500;
    static const int HP = 800;
    static const int BUILD_TIME = (1500*1000)/100;

    OrcBarracks(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;

};

#endif // ORCBARRACKS_HPP
