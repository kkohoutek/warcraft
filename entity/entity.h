#ifndef ENTITY_H
#define ENTITY_H

#define SHOW_HP_BARS 1

#include <QGraphicsItem>
#include <QPixmap>
#include "animation.h"

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

    bool isAlive() const;
    void setHighlighted(bool h);

    qreal distanceFrom(Entity *entity) const;
    qreal distanceFrom(QPointF point) const;

    /* absolutní pozice středu entity */
    QPointF center() const;


protected:
    float scaleX;
    float scaleY;


 private:
    int hp;
    int maxHP;
    Animation *currentAnimation;

    bool highlighted;

};



#endif // ENTITY_H
