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
    painter->scale(0.5f,0.5f);
    if(highlighted){
        painter->setPen(QPen(Qt::green));
        painter->drawRect(boundingRect());
    }
    if(SHOW_HP_BARS){
        painter->scale(2,2);
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

void Entity::setHighlighted(bool h) {
    highlighted = h;
}


qreal Entity::distanceFrom(Entity *entity){
    return QLineF(boundingRect().translated(pos()).center(), entity->boundingRect().translated(entity->pos()).center()).length();

}

qreal Entity::distanceFrom(QPointF point){
    return QLineF(boundingRect().translated(pos()).center(), point).length();
}
