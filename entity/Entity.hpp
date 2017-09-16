#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <QGraphicsItem>
#include <QPixmap>
#include "Animation.hpp"

class Entity : public QGraphicsItem
{

public:
    Entity(QPointF pos);
    virtual ~Entity();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void update() = 0;
    virtual void die();

    void setCurrentAnimation(Animation *anim);
    Animation *getCurrentAnimation() const;

    void damage(int amount);

    void setHP(int hp);
    int getHP() const;

    void setMaxHP(int hp);
    int getMaxHP() const;

    virtual bool isAlive() const;
    void setHighlighted(bool h);

    qreal distanceFrom(Entity *entity) const;
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
