#ifndef UNIT_H
#define UNIT_H

#include "entity/entity.h"
#include "pathfinding/node.h"
#include <QQueue>
#include <QVector2D>

class Unit : public Entity
{
public:

    Unit(QPointF pos, float speed, int damage, int armor, int range);
    virtual ~Unit();

    void setTarget(QPointF target);

    virtual void attack(Entity *victim);
    virtual void die() override;

    /* Aktualizace dosavadní animace na základě úhlu pohybu */
    virtual void updateAnimation();

    virtual void update() override;
    virtual void cancel();

    /* Začni se hýbat, setTarget musí být voláno před použitím */
    void move();

    void setPath(QList<QPointF> list);


    QVector2D direction() const;

    QPointF getTarget() const;
    float getSpeed() const;
    void setSpeed(float speed);
    void stopMoving();
    bool isMoving() const;

protected:
    float speed;
    int damage;
    int armor;
    int range;

    // animation sets
    QList<Animation *> movementAnims;
    QList<Animation *> attackAnims;
    QList<Animation *> deathAnims;
    QList<Animation *> *currentAnimationSet;

    QPointF targetPoint;
    QQueue<QPointF> path; // collection of target points
    Entity *targetEntity = nullptr;

    void approachTarget();
    bool moving = false;    // viditelný rect



};

#endif // UNIT_H

