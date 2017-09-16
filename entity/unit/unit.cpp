#include "Unit.hpp"
#include <QtMath>

Unit::Unit(QPointF pos, Unit::Type type, float speed, int damage, int armor, int range) : Entity(pos)
{
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->armor = armor;
    this->type = type;

    scaleX = 2;
    scaleY = 2;

    currentAnimationSet = &movementAnims;
}

Unit::~Unit() {
    setCurrentAnimation(nullptr);

    qDeleteAll(movementAnims);
    qDeleteAll(deathAnims);
    qDeleteAll(attackAnims);
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

    if(targetEntity) {
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
        // Přibliž se k cíli
        moveBy(speed * direction().x(), speed * direction().y());
    }

    if(distanceFrom(targetPoint) < 1){
        moving = false;
        if(!path.isEmpty()) {
            setTarget(path.dequeue());
            move();
        } else {
            stopMoving();
        }
    }

}

void Unit::setPath(const QList<QPointF> &list){
    if(!path.isEmpty() && path.last() == list.last()) return;
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
    targetEntity = nullptr;
}

void Unit::move() {
    moving = true;
    currentAnimationSet = &movementAnims;
}


