#include "goldmine.h"

Goldmine::Goldmine(QPointF pos) : Entity(pos)
{
    setMaxHP(20000);
    setHP(20000);
    QList<QList<int>> *basicAnimationFrames = new QList<QList<int>>();
    basicAnimationFrames->append(QList<int>() << 8 << 5);
    setCurrentAnimation(new Animation(new QPixmap(":graphics/MISC"), 55, 45, basicAnimationFrames, 0, false));
}

QRectF Goldmine::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void Goldmine::update()
{

}



