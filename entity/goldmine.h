#ifndef GOLDMINE_H
#define GOLDMINE_H

#include "entity.h"
#include "animation.h"



class Goldmine : public Entity
{
public:
    ~Goldmine();
    void update();
    Goldmine(QPointF pos);
    Animation *basicAnimation;
    // QGraphicsItem interface
    QRectF boundingRect() const;


    // Entity interface

private:
     Animation *currentAnimation;
};

#endif // GOLDMINE_H
