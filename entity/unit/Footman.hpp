#ifndef FOOTMAN_HPP
#define FOOTMAN_HPP

#include "Unit.hpp"
#include "ResourceManager.hpp"



class Footman : public Unit
{
public:
    Footman(QPointF pos, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // FOOTMAN_HPP
