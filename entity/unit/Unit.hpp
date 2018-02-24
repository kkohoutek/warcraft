#ifndef UNIT_HPP
#define UNIT_HPP

#include <QQueue>
#include <QVector2D>
#include "entity/Entity.hpp"
#include "pathfinding.hpp"

/*
 * Tato třída je základem všech jednotek.
 * Nemělá by být instancována přímo, nýbrž být rozšířena specifickými podtřídami.
 */
class Unit : public Entity
{
public:
    // C++ nemá reflexi, opravte to
    enum Type {
        NONE,
        DAEMON,
        FOOTMAN,
        PEASANT,
        PEON,
        GRUNT
    };

    Unit(QPointF pos, Unit::Type type, float speed, float damage, int armor, int range, int attackSpeed);
    Unit();
    virtual ~Unit();

    void            setTarget(QPointF target);
    void            setPath(const PATH &list);
    void            goTo(QPointF goal);
    void            useGraph(Graph *graph) { this->graph = graph; }

    virtual void    attack(Entity *victim);
    virtual void    die() override;
    virtual void    damaged(float amount, Entity *source) override;

    // Aktualizace dosavadní animace na základě úhlu pohybu */
    virtual void    updateAnimation();

    virtual void    update() override;
    virtual void    cancel();

    // Začni se hýbat, setTarget musí být voláno před použitím
    void            move();

    void            stopMoving();
    QVector2D       direction() const;
    bool            isWithinRange(Entity *entity) const;

    void            setType(Unit::Type t)  { type = t; }
    Unit::Type      getType() const        { return type; }
    bool            isMoving() const       { return moving; }
    float           getDamage() const      { return damage; }
    void            setDamage(float d)     { damage = d; }
    float           getSpeed() const       { return speed; }
    void            setSpeed(float s)      { speed = s; }
    int             getArmor() const       { return armor; }
    void            setArmor(int a)        { armor = a; }
    int             getAttackSpeed()       { return attackSpeed; }
    void            setAttackSpeed(int as) { attackSpeed = as; }

    Entity          *getTargetEntity()     { return targetEntity; }

protected:
    Unit::Type type;
    float speed;
    float damage;
    int armor;
    int range;
    int attackSpeed;

    bool moving = false;
    int attackCooldown = 0;

    // animation sets
    QList<Animation *> movementAnims;
    QList<Animation *> attackAnims;
    QList<Animation *> deathAnims;
    QList<Animation *> *currentAnimationSet; // Ukazuje na jeden z předešlých listů

    QPointF targetPoint;
    PATH path;
    Graph *graph = nullptr; // pointer to pathfinding graph
    Entity *targetEntity = nullptr;

};

#endif // UNIT_HPP

