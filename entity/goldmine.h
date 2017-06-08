#ifndef GOLDMINE_H
#define GOLDMINE_H

#include "entity.h"



class Goldmine : public Entity
{
public:
    Goldmine(QPointF pos);
    void update();

    // QGraphicsItem interface
    QRectF boundingRect() const;

};

#endif // GOLDMINE_H
