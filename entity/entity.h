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

    int getHP();
    void setHP(int hp);


protected:
    QPixmap *spriteSheet;
    Animation *currentAnimation;

    int hp = 0; // 0 nezranitelnost
    int width;
    int height;

    void setCurrentAnimation(Animation *anim);





};

#endif // ENTITY_H
