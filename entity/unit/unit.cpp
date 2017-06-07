
#include "unit.h"
#include <QtMath>
#include <QPainter>
#include <QDebug>

Unit::Unit(QPointF pos, int speed, int damage, int armor, int range):Entity(pos)
{
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->armor = armor;
    setPos(pos);
}

void Unit::moveToTarget()
{
    if(pos() == targetPoint || (targetEntity != NULL && this->collidesWithItem(targetEntity))){
        getCurrentAnimation()->setCurrentFrame(0);
        return;
    }

    this->moveBy(2 * cos(qDegreesToRadians(path.angle())),2 * sin(qDegreesToRadians(path.angle())));
}

void Unit::updateAnimation(){

    if(path.angle() >= 0 && path.angle() < 45){
        setCurrentAnimation(currentAnimationSet->at(0));
    } else if (path.angle() > 135 && path.angle() <= 180){
        setCurrentAnimation(currentAnimationSet->at(1));
    } else if (path.angle()){


    }
}

void Unit::update(){
    qDebug() << path.angle();
    updateAnimation();
    moveToTarget();

}

void Unit::setTarget(QPointF target){
    targetPoint = target;
    path = QLineF(pos(), targetPoint);

    currentAnimationSet = movementAnims;
}



