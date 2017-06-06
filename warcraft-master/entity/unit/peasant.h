#ifndef PEASANT_H
#define PEASANT_H

#include "worker.h"



class Peasant : public Worker
{
public:
    Peasant(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const;
};

#endif // PEASANT_H
