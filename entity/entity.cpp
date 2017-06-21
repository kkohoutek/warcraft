#include "entity.h"
#include "common.h"
#include <QGraphicsScene>

Entity::Entity(QPointF pos) {
    this->setPos(pos);
    scaleX = 1;
    scaleY = 1;

    deleteTimer = new QTimer();
    deleteTimer->setInterval(CORPSE_STAY_TIME);
    deleteTimer->setSingleShot(true);
    connect(deleteTimer, &QTimer::timeout, this, &cleanUp);
}

Entity::~Entity() {
    delete currentAnimation;
    delete deleteTimer;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->scale(scaleX,scaleY);
    if(currentAnimation != NULL){
        currentAnimation->draw(painter);
    }
    painter->scale(1/scaleX,1/scaleY);
    if(highlighted){
        painter->setPen(QPen(Qt::green));
        painter->drawRect(boundingRect());
    }
    if(SHOW_HP_BARS && hp > 0){
        painter->setBrush(QBrush(Qt::green));
        painter->setPen(QPen(Qt::green));
        painter->drawRect(boundingRect().topLeft().x(),boundingRect().topLeft().y()-5, hp*boundingRect().width()/maxHP, 1.25f); // health bar
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Entity::die() {
    hp = 0;
    deleteTimer->start();
}


void Entity::setCurrentAnimation(Animation *anim) {
    if(currentAnimation != NULL) {
        currentAnimation->stop();
        currentAnimation->setCurrentFrame(0);
    }
    currentAnimation = anim;
    //currentAnimation->start();
}

Animation *Entity::getCurrentAnimation() const {
    return currentAnimation;
}

void Entity::damage(int amount){
    hp -= amount;
    if(hp < 0) hp = 0;
}

void Entity::setHP(int hp) {
    this->hp = hp;
}

int Entity::getHP() const {
    return hp;
}

void Entity::setMaxHP(int hp) {
    maxHP = hp;
}

int Entity::getMaxHP() const {
    return maxHP;
}

void Entity::setHighlighted(bool h) {
    highlighted = h;
}


qreal Entity::distanceFrom(Entity *entity) const {
    return QLineF(boundingRect().translated(pos()).center(), entity->boundingRect().translated(entity->pos()).center()).length();

}

qreal Entity::distanceFrom(QPointF point) const {
    return QLineF(boundingRect().translated(pos()).center(), point).length();
}

QPointF Entity::center() const {
    return boundingRect().translated(pos()).center();

}

void Entity::cleanUp(){
    scene()->removeItem(this);
    delete this;
}
