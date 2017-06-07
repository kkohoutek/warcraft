#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QObject>
#include "animation.h"

class Entity : public QGraphicsItem
{
public:
    Entity(QPointF pos);
    virtual ~Entity();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void update() = 0;
    void setCurrentAnimation(Animation *anim);
    Animation *getCurrentAnimation();

    void setHP(int hp);
    int getHP();

    void setMaxHP(int hp);
    int getMaxHP();


    void setHighlighted(bool h);

    qreal distanceFrom(Entity *entity);
    qreal distanceFrom(QPointF point);


 private:
    int hp = 0;
    int maxHP;
    Animation *currentAnimation;

    bool highlighted = false;



};



#endif // ENTITY_H
