#ifndef TREES_HPP
#define TREES_HPP

#include "Entity.hpp"



class Trees : public Entity
{
public:
    Trees(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const;


};

#endif // TREES_HPP
