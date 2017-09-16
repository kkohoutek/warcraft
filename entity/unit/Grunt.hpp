#ifndef GRUNT_HPP
#define GRUNT_HPP

#include "Unit.hpp"
#include "ResourceManager.hpp"

class Grunt : public Unit
{
public:
    Grunt(QPointF pos, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // GRUNT_HPP
