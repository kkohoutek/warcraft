#ifndef GRUNT_H
#define GRUNT_H

#include "unit.h"
#include "resourcemanager.h"

class Grunt : public Unit
{
public:
    Grunt(QPointF pos, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // GRUNT_H
