#ifndef TREES_HPP
#define TREES_HPP

#include "Entity.hpp"



class Trees : public Entity
{
public:
    Trees(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const;

    // Entity interface
    void update();


};

#endif // TREES_HPP
