#include "entity.h"

#include <QPainter>

Entity::Entity(QPointF pos, QPixmap *spriteSheet, int width, int height) {
    this->spriteSheet = spriteSheet;
    this->width = width;
    this->height = height;
    this->setPos(pos);

}

Entity::~Entity()
{
    delete spriteSheet;
}



void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->drawPixmap(0, 0, *spriteSheet, currentAnimation->currentPositionX(), currentAnimation->currentPositionY(),
                                            currentAnimation->getSubImageWidth(), currentAnimation->getSubImageHeight());

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Entity::boundingRect() const {
    return QRectF(0,0,width,height);
}

int Entity::getHP(){
    return hp;
}

void Entity::setHP(int hp){
    this->hp = hp;
}

void Entity::setCurrentAnimation(Animation *anim) {
    currentAnimation = anim;
}
