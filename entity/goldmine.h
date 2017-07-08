#ifndef GOLDMINE_H
#define GOLDMINE_H

#include "entity.h"
#include "resources.h"


class Goldmine : public Entity
{
public:
    Goldmine(QPointF pos, Resources &res);
    void update();

    // QGraphicsItem interface
    QRectF boundingRect() const;

};

#endif // GOLDMINE_H
