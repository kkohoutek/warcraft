#ifndef TREES_H
#define TREES_H

#include "entity.h"



class Trees : public Entity
{
public:
    Trees(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const;

    // Entity interface
    void update();


};

#endif // TREES_H
