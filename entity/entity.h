#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPixmap>
#include "animation.h"



class Entity : public QGraphicsItem
{
public:
    Entity(QPointF pos, QPixmap *spriteSheet, int width, int height);
    virtual ~Entity();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    virtual void update() = 0;
    void setCurrentAnimation(Animation *anim);

    void setHP(int hp);
    int getHP();

protected:
    QPixmap *spriteSheet;



 private:
    int width;
    int height;
    int hp = -1;
    Animation *currentAnimation;

};



#endif // ENTITY_H
