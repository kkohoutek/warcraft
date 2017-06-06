#ifndef GOLDMINE_H
#define GOLDMINE_H

#include "entity.h"



class Goldmine : public Entity
{
public:
    Goldmine(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const;

    // Entity interface
    void update();
};

#endif // GOLDMINE_H
