#ifndef FOOTMAN_HPP
#define FOOTMAN_HPP

#include "Unit.hpp"
#include "ResourceManager.hpp"

class Footman : public Unit
{
public:
    static const int COST_GOLD = 400;
    static const int COST_LUMBER = 0;

    Footman(QPointF pos, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // FOOTMAN_HPP
