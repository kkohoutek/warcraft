#ifndef FOOTMAN_H
#define FOOTMAN_H

#include "unit.h"
#include "resources.h"



class Footman : public Unit
{
public:
    Footman(QPointF pos, Resources &res);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // FOOTMAN_H
