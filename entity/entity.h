#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPixmap>
#include "animation.h"

class Entity : public QGraphicsItem
{

public:
    static const bool SHOW_HP_BARS = true;
    static const int CORPSE_STAY_TIME = 5000;

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
    QPointF center() const;


protected:
    float scaleX;
    float scaleY;


 private:
    int hp;
    int maxHP;
    Animation *currentAnimation = NULL;

    bool highlighted = false;

};



#endif // ENTITY_H
