#ifndef GRUNT_H
#define GRUNT_H

#include "unit.h"



class Grunt : public Unit
{
public:
    Grunt(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // GRUNT_H
