#include "Goldmine.hpp"

Goldmine::Goldmine(QPointF pos, ResourceManager *rm) : Entity(pos) {
    setMaxHP(40000);
    setHP(40000);
    QList<QList<int>> basicAnimationFrames;
    basicAnimationFrames.append(QList<int>() << 8 << 5);
    setCurrentAnimation(new Animation(rm->getSprite("MISC"), 55, 45, basicAnimationFrames, 0));

    scaleX = 2;
    scaleY = 2;
}

QRectF Goldmine::boundingRect() const {
    return QRectF(-8,0,96,92);
}


