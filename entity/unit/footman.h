#ifndef FOOTMAN_H
#define FOOTMAN_H

#include "unit.h"
#include "resourcemanager.h"



class Footman : public Unit
{
public:
    Footman(QPointF pos, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // FOOTMAN_H
