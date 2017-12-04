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

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void update();
    virtual void die();
    virtual void damaged(float amount, Entity *source);

    void setHP(float hp)            { this->hp = hp; }
    float getHP() const             { return hp; }

    void setMaxHP(int hp)           { this->maxHP = hp; }
    int getMaxHP() const            { return maxHP; }

    virtual bool isAlive() const    { return hp > 0; }
    virtual bool canSelect() const  { return isVisible() && isAlive(); }

    void setHighlighted(bool h)     { highlighted = h; }
    bool isHighlighted() const      { return highlighted; }

    virtual float distanceFrom(Entity *entity) const ;
    virtual float distanceFrom(QPointF point) const;

    // absolutní pozice středu entity
    QPointF center() const;

    // absolute boundingrect
    QRectF boundingRect2() const;

    int getID() const { return id; }

protected:
    float scaleX = 1;
    float scaleY = 1;

    void setCurrentAnimation(Animation *anim);
    Animation *getCurrentAnimation() const  { return currentAnimation; }

 private:
    Animation *currentAnimation = nullptr;

    int id;
    float hp              = 0;
    int maxHP             = 0;
    bool highlighted      = false;

    static int newID;

};



#endif // ENTITY_HPP
