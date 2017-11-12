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

    void damage(int amount);

    void setHP(int hp)              { this->hp = hp; }
    int getHP() const               { return hp; }

    void setMaxHP(int hp)           { this->maxHP = hp; }
    int getMaxHP() const            { return maxHP; }

    virtual bool isAlive() const    { return hp > 0; }
    virtual bool canSelect() const  { return isVisible() && isAlive(); }
    void setHighlighted(bool h)     { highlighted = h; }

    float distanceFrom(Entity *entity) const ;
    float distanceFrom(QPointF point) const;

    // absolutní pozice středu entity
    QPointF center() const;

    // absolute boundingrect
    QRectF boundingRect2() const;

protected:
    float scaleX = 1;
    float scaleY = 1;

    void setCurrentAnimation(Animation *anim);
    Animation *getCurrentAnimation() const  { return currentAnimation; }

 private:
    Animation *currentAnimation = nullptr;

    int hp              = 0;
    int maxHP           = 0;
    bool highlighted    = false;

};



#endif // ENTITY_HPP
