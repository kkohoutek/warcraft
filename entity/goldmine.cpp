#include "goldmine.h"

Goldmine::Goldmine(QPointF pos) : Entity(pos)
{
    setMaxHP(20000);
    setHP(20000);
    setCurrentAnimation(new Animation(new QPixmap(":graphics/GOLDMINE"), 48, 48, new QList<QList<int>>(), 0, false));

}

QRectF Goldmine::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void Goldmine::update()
{

}
