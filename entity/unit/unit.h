#ifndef UNIT_H
#define UNIT_H

#include "entity/entity.h"



class Unit : public Entity
{
public:

    Unit(QPointF pos, int speed, int damage, int armor, int range);

    void setTarget(QPointF target);

    /* Aktualizace dosavadní animace na základě úhlu pohybu */
    virtual void updateAnimation();

    virtual void update() override;
    virtual void cancel();

    /* Začni se hýbat, setTarget musí být voláno před použitím */
    void move();

    void stopMoving();
    bool isMoving();

protected:
    int speed;
    int damage;
    int armor;
    int range;

    // animation sets
    QList<Animation *> *movementAnims;
    QList<Animation *> *attackAnims;
    QList<Animation *> *deathAnims;
    QList<Animation *> *currentAnimationSet;

    QPointF targetPoint;
    Entity *targetEntity = NULL;

    void moveToTarget();
    bool moving = false;

};

#endif // UNIT_H

