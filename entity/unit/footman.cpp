#include "footman.h"

Footman::Footman(QPointF pos) : Unit(pos, 60, 1, 2, 0)
{

    setMaxHP(60);
    setHP(60);
    QPixmap *spriteSheet = new QPixmap(":graphics/FOOTMAN");
    QPixmap *spriteSheetFlipped = new QPixmap(":graphics/FOOTMAN2");

    movementAnims = new QList<Animation *>();
    QList<QList<int>> *walk0DegFrames = new QList<QList<int>>();
    walk0DegFrames->append(QList<int>() << 2 << 0);
    walk0DegFrames->append(QList<int>() << 2 << 1);
    walk0DegFrames->append(QList<int>() << 2 << 2);
    walk0DegFrames->append(QList<int>() << 2 << 1);

    Animation *walk0Deg = new Animation(spriteSheet, 48,48, walk0DegFrames, 250, true);

    movementAnims->append(walk0Deg);

    QList<QList<int>> *walk180DegFrames = new QList<QList<int>>();
    walk180DegFrames->append(QList<int>() << 14-2 << 0);
    walk180DegFrames->append(QList<int>() << 14-2 << 1);
    walk180DegFrames->append(QList<int>() << 14-2 << 2);
    walk180DegFrames->append(QList<int>() << 14-2 << 1);

    Animation *walk180Deg = new Animation(spriteSheetFlipped, 48,48, walk180DegFrames, 250, true);

    movementAnims->append(NULL);
    movementAnims->append(NULL);
    movementAnims->append(NULL);
    movementAnims->append(walk180Deg);

}

QRectF Footman::boundingRect() const
{
    return QRectF(6,6,36,36);
}
