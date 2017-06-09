#include "unit.h"
#include <QDebug>
#include <QVector2D>

Unit::Unit(QPointF pos, int speed, int damage, int armor, int range):Entity(pos)
{
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->armor = armor;

    currentAnimationSet = movementAnims;
}

Unit::~Unit() {
    for(Animation *a : *movementAnims){
        delete a;
    }
    for(Animation *a : *deathAnims){
        delete a;
    }
    for(Animation *a : *attackAnims){
        delete a;
    }

    delete movementAnims;
    delete attackAnims;
    delete deathAnims;

}

void Unit::moveToTarget()
{
    //currentAnimationSet = movementAnims;
    /*
    if(pos() == targetPoint || contains(targetPoint)){
        //getCurrentAnimation()->setCurrentFrame(0);
        return;
    }*/

    QVector2D dir(targetPoint - boundingRect().translated(pos()).center());
    dir.normalize();
    moveBy(speed * dir.x(), speed * dir.y());

}

void Unit::updateAnimation(){
    qreal angle = QLineF(boundingRect().translated(pos()).center(), targetPoint).angle();

    int index = 0;
    if(currentAnimationSet->size() == 8){
        if(angle >= 0 && angle < 45){
            index = 0;
        } else if (angle >= 45 && angle < 90){
            index = 1;
        } else if (angle >= 90 && angle < 135){
            index = 2;
        } else if (angle >= 135 && angle < 180){
            index = 3;
        } else if (angle >= 180 && angle < 225){
            index = 4;
        } else if (angle >= 225 && angle < 270){
            index = 5;
        } else if (angle >= 270 && angle < 315){
            index = 6;
        } else if(angle >= 315){
            index = 7;
        }
    } else {
        index = 0;
    }
    qDebug() << index;
    setCurrentAnimation(currentAnimationSet->at(index));
}

void Unit::update(){
    if(moving){
        moveToTarget();
    }

    if(distanceFrom(targetPoint) < 2){
        getCurrentAnimation()->setCurrentFrame(0);
        moving = false;
    }
}

void Unit::setTarget(QPointF target){
    targetPoint = target;
    currentAnimationSet = movementAnims;
    updateAnimation();
}

void Unit::cancel(){
    targetEntity = NULL;
}

void Unit::move() {
    //currentAnimationSet = movementAnims;
    moving = true;
}

void Unit::stopMoving(){
    moving = false;
}

bool Unit::isMoving(){
    return moving;

}




