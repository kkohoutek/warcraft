#ifndef FOOTMAN_H
#define FOOTMAN_H

#include "unit.h"



class Footman : public Unit
{
public:
    Footman(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // FOOTMAN_H
