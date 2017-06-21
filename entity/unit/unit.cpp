#include "unit.h"
#include <QDebug>
#include <QtMath>

Unit::Unit(QPointF pos, float speed, int damage, int armor, int range):Entity(pos)
{
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->armor = armor;

    scaleX = 2;
    scaleY = 2;

    currentAnimationSet = movementAnims;
}

Unit::~Unit() {
    QList<QPixmap *> spriteSheets;
    QList<Animation *> anims;
    anims.append(*movementAnims);
    anims.append(*attackAnims);
    anims.append(*deathAnims);

    for(Animation *a : anims){
        if(!spriteSheets.contains(a->getSpriteSheet())){
            spriteSheets.append(a->getSpriteSheet());
        }
        delete a;
    }

    for(QPixmap *s : spriteSheets){
        delete s;
    }

    delete movementAnims;
    delete attackAnims;
    delete deathAnims;

    setCurrentAnimation(NULL);

}

void Unit::approachTarget() {
    moveBy(speed * direction().x(), speed * direction().y());
}

void Unit::updateAnimation(){
    qreal angle = QLineF(center(), targetPoint).angle();

    int index = 0;
    if(currentAnimationSet->size() == 8){
        if(angle >= 30 && angle <= 60){
            index = 1;
        } else if (angle > 60 && angle < 120){
            index = 2;
        } else if (angle >= 120 && angle <= 150){
            index = 3;
        } else if (angle > 150 && angle < 210){
            index = 4;
        } else if (angle >= 210 && angle <= 240){
            index = 5;
        } else if (angle > 240 && angle < 300){
            index = 6;
        } else if (angle >= 300 && angle <= 330){
            index = 7;
        }
    }

    //setCurrentAnimation(currentAnimationSet->at(qFloor(angle/45)));
    setCurrentAnimation(currentAnimationSet->at(index));
    getCurrentAnimation()->start();

}

void Unit::update(){

    if(moving){
        approachTarget();
    }

    if(distanceFrom(targetPoint) < 1){
        stopMoving();
    }
}

void Unit::attack(Entity *victim) {
    targetEntity = victim;
    setTarget(victim->center());
    move();

}

void Unit::die() {
    stopMoving();
    setCurrentAnimation(deathAnims->at(0));
    getCurrentAnimation()->start();
    Entity::die();
}


void Unit::setTarget(QPointF target){
    targetPoint = target;
    currentAnimationSet = movementAnims;
    updateAnimation();
}

QVector2D Unit::direction() const {
    return QVector2D(targetPoint - center()).normalized();
}

void Unit::cancel(){
    targetEntity = NULL;
}

void Unit::move() {
    moving = true;
}

void Unit::stopMoving(){
    moving = false;
    getCurrentAnimation()->setCurrentFrame(0);
    getCurrentAnimation()->stop();
}

bool Unit::isMoving() const {
    return moving;

}

QPointF Unit::getTarget() const {
    return targetPoint;

}

void Unit::setSpeed(float speed){
    this->speed = speed;
}

float Unit::getSpeed() const {
    return speed;
}




