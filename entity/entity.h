#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QObject>
#include "animation.h"



class Entity : public QGraphicsItem
{
public:
    Entity(QPointF pos, QPixmap *spriteSheet);
    virtual ~Entity();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    virtual void update() = 0;
    void setCurrentAnimation(Animation *anim);

    void setHP(int hp);
    int getHP();

    void setMaxHP(int hp);
    int getMaxHP();

protected:
    QPixmap *spriteSheet;



 private:
    int width;
    int height;
    int hp = 0;
    int maxHP;

    Animation *currentAnimation;

};



#endif // ENTITY_H
