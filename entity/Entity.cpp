#include "Entity.hpp"
#include <QGraphicsScene>

#define SHOW_HP_BARS 1

Entity::Entity(QPointF pos) {
    this->setPos(pos);
}

Entity::~Entity() {
    delete currentAnimation;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    if(currentAnimation){
        painter->scale(scaleX,scaleY);
        currentAnimation->draw(painter);
        painter->scale(1/scaleX,1/scaleY);
    }
    {
        QRectF r = boundingRect();
        if(highlighted){
            painter->setPen(QPen(Qt::green));
            painter->drawRect(r);
        }
        if(SHOW_HP_BARS && hp > 0){
            painter->setBrush(QBrush(Qt::green));
            painter->setPen(QPen(Qt::green));
            painter->drawRect(r.topLeft().x(), r.topLeft().y()-5, hp*r.width()/maxHP, 1.25f); // health bar
        }
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Entity::update() {
    if(!isAlive()) return;
}

void Entity::die() {
    hp = 0;
    setZValue(-1);
}

void Entity::setCurrentAnimation(Animation *anim) {
    if(currentAnimation) {
        currentAnimation->stop();
        currentAnimation->setCurrentFrame(0);
    }
    currentAnimation = anim;
}

void Entity::damage(int amount){
    hp -= amount;
    if(hp < 0) die();
}

float Entity::distanceFrom(QPointF point) const {
    return QLineF(center(), point).length();
}

float Entity::distanceFrom(Entity *entity) const {
    return distanceFrom(entity->center());
}

QPointF Entity::center() const {
    return boundingRect2().center();
}

QRectF Entity::boundingRect2() const {
    return boundingRect().translated(pos());
}
