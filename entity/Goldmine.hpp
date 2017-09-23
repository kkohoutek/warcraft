#ifndef GOLDMINE_HPP
#define GOLDMINE_HPP

#include "Entity.hpp"
#include "ResourceManager.hpp"

class Goldmine : public Entity
{
public:
    Goldmine(QPointF pos, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const;

};

#endif // GOLDMINE_HPP
