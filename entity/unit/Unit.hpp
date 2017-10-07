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

    Unit(QPointF pos, Unit::Type type, float speed, int damage, int armor, int range);
    virtual ~Unit();

    void            setTarget(QPointF target);
    void            setPath(const QList<Node **> &list);
    void            goTo(QPointF goal);
    void            useGraph(Graph *graph) { this->graph = graph; }

    virtual void    attack(Entity *victim);
    virtual void    die() override;

    // Aktualizace dosavadní animace na základě úhlu pohybu */
    virtual void    updateAnimation();

    virtual void    update() override;
    virtual void    cancel();

    // Začni se hýbat, setTarget musí být voláno před použitím
    void            move();

    void            stopMoving();
    QVector2D       direction() const;

    Unit::Type      getType() const        { return type; }
    bool            isMoving() const       { return moving; }

protected:
    float speed;
    int damage;
    int armor;
    int range;

    bool moving = false;

    // animation sets
    QList<Animation *> movementAnims;
    QList<Animation *> attackAnims;
    QList<Animation *> deathAnims;
    QList<Animation *> *currentAnimationSet; // Ukazuje na jeden z předešlých listů

    QPointF targetPoint;
    QQueue<Node **> path;
    Graph *graph = nullptr; // pointer to pathfinding graph
    Entity *targetEntity = nullptr;

private:
    Unit::Type type;

};

#endif // UNIT_HPP

