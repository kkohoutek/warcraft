#ifndef GRUNT_H
#define GRUNT_H

#include "unit.h"
#include "resources.h"



class Grunt : public Unit
{
public:
    Grunt(QPointF pos, Resources &res);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // GRUNT_H
