#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QObject>
#include "animation.h"

class Entity : public QGraphicsItem
{
public:
    static const bool SHOW_HP_BARS = true;

    Entity(QPointF pos);
    virtual ~Entity();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void update() = 0;
    void setCurrentAnimation(Animation *anim);
    Animation *getCurrentAnimation();

    void damage(int amount);

    void setHP(int hp);
    int getHP();

    void setMaxHP(int hp);
    int getMaxHP();


    void setHighlighted(bool h);

    qreal distanceFrom(Entity *entity);
    qreal distanceFrom(QPointF point);
    QPointF center();

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
