#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <QGraphicsItem>
#include <QPixmap>
#include "Animation.hpp"

/*
 * Tato třída je základem všech entit.
 * Neměla by se instancovat přímo, nýbrž být rozšířena specifickými podtřídami.
 */
class Entity : public QGraphicsItem
{
public:
    Entity(QPointF pos);
    virtual ~Entity();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void update();
    virtual void die();

    void setCurrentAnimation(Animation *anim);
    Animation *getCurrentAnimation() const  { return currentAnimation; }

    void damage(int amount);

    void setHP(int hp)              { this->hp = hp; }
    int getHP() const               { return hp; }

    void setMaxHP(int hp)           { this->maxHP = hp; }
    int getMaxHP() const            { return maxHP; }

    virtual bool isAlive() const    { return hp > 0; }
    void setHighlighted(bool h)     { highlighted = h; }

    qreal distanceFrom(Entity *entity) const ;
    qreal distanceFrom(QPointF point) const;

    // absolutní pozice středu entity
    QPointF center() const;

    // absolute boundingrect
    QRectF boundingRect2() const;

protected:
    float scaleX;
    float scaleY;


 private:
    int hp;
    int maxHP;
    Animation *currentAnimation;

    bool highlighted;

};



#endif // ENTITY_HPP
