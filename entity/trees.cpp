#include "trees.h"

Trees::Trees(QPointF pos) : Entity(pos){
    setMaxHP(0);
    setHP(0);

    QList<QList<int>> *frame = new QList<QList<int>>();
    frame->append(QList<int>() << 0 << 0);
    Animation *tree = new Animation(QPixmap(":graphics/WORLD"), 96, 96, frame, 0, false);
    setCurrentAnimation(tree);
}

QRectF Trees::boundingRect() const {
    return QRectF(0,0,192,192);

}

void Trees::update()
{

}
