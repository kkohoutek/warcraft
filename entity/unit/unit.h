#ifndef UNIT_H
#define UNIT_H

#include "entity/entity.h"



class Unit : public Entity
{
public:

    Unit(QPointF pos, int speed, int damage, int armor, int range);

    void moveToTarget();
    void setTarget(QPointF target);

    /* Aktualizace dosavadní animace na základě úhlu pohybu */
    virtual void updateAnimation();

    virtual void update() override;

protected:
    int speed;
    int damage;
    int armor;
    int range;

    QList<Animation *> *movementAnims;
    QList<Animation *> *attackAnims;
    QList<Animation *> *deathAnims;
    QList<Animation *> *currentAnimationSet;

    QPointF targetPoint;
    QLineF  path;
    Entity *targetEntity = NULL;



};

#endif // UNIT_H

