#include "entity.h"
#include "common.h"

Entity::Entity(QPointF pos) {
    this->setPos(pos);
}

Entity::~Entity() {
    delete currentAnimation;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->scale(2,2);
    currentAnimation->draw(painter);

    if(SHOW_HP_BARS){
        painter->setBrush(QBrush(Qt::green));
        painter->setPen(QPen(Qt::green));
        painter->drawRect(0,0, hp*boundingRect().width()/maxHP, 1.5f); // health bar
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void Entity::setCurrentAnimation(Animation *anim) {
    currentAnimation = anim;
}

Animation *Entity::getCurrentAnimation() {
    return currentAnimation;
}

void Entity::setHP(int hp) {
    this->hp = hp;
}

int Entity::getHP(){
    return hp;
}

void Entity::setMaxHP(int hp) {
    maxHP = hp;
}

int Entity::getMaxHP() {
    return maxHP;
}
