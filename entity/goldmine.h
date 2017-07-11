#ifndef GOLDMINE_H
#define GOLDMINE_H

#include "entity.h"
#include "resourcemanager.h"


class Goldmine : public Entity
{
public:
    Goldmine(QPointF pos, ResourceManager *rm);
    void update();

    // QGraphicsItem interface
    QRectF boundingRect() const;

};

#endif // GOLDMINE_H
