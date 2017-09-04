#include "unit.h"
#include <QDebug>
#include <QtMath>

Unit::Unit(QPointF pos, float speed, int damage, int armor, int range) : Entity(pos)
{
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->armor = armor;

    scaleX = 2;
    scaleY = 2;

    currentAnimationSet = &movementAnims;
}

Unit::~Unit() {
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

    setCurrentAnimation(currentAnimationSet->at(index));
    getCurrentAnimation()->start();
}

void Unit::update(){
    if(!isAlive()) {

        die();
        return;
    }

    if(targetEntity != NULL) {
        if(targetEntity->isAlive()){
            if(distanceFrom(targetEntity) <= range + 8){
                moving = false;
                if(currentAnimationSet != &attackAnims){
                    currentAnimationSet = &attackAnims;
                    updateAnimation();
                }
                targetEntity->damage(damage);
            }
        } else {
            cancel();
            currentAnimationSet = &movementAnims;
            updateAnimation();
            stopMoving();
        }
    }

    if(moving){
        approachTarget();
    }

    if(distanceFrom(targetPoint) < 1){
        stopMoving();
        if(!path.isEmpty()) {
            setTarget(path.dequeue());
            move();
        }
    }

}

void Unit::setPath(QList<QPointF> list){
    path.clear();
    for(QPointF p : list){
        path.enqueue(p);
    }
    if(!path.isEmpty()){
        setTarget(path.dequeue());
        move();
    }
}

void Unit::attack(Entity *victim) {
    setTarget(victim->center());
    targetEntity = victim;
    move();

}

void Unit::die() {
    stopMoving();
    if(getCurrentAnimation() != deathAnims.at(0)){
        setCurrentAnimation(deathAnims.at(0));
        getCurrentAnimation()->start();
    }
    Entity::die();
}

void Unit::stopMoving(){
    moving = false;
    if(currentAnimationSet == &movementAnims){
        getCurrentAnimation()->setCurrentFrame(0);
        getCurrentAnimation()->stop();
    }
}


void Unit::setTarget(QPointF target){
    targetPoint = target;
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
    currentAnimationSet = &movementAnims;
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




