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

    void setHP(int hp);
    int getHP();

    void setMaxHP(int hp);
    int getMaxHP();

protected:
    QPixmap *spriteSheet;
    Animation *currentAnimation;

 private:
    int hp = 0;
    int maxHP;



};



#endif // ENTITY_H
