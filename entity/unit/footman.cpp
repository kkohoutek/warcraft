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

    movementAnims->append(walk180Deg);

    QList<QList<int>> *walk45DegFrames = new QList<QList<int>>();
    walk45DegFrames->append(QList<int>() << 6 << 0);
    walk45DegFrames->append(QList<int>() << 6 << 1);
    walk45DegFrames->append(QList<int>() << 6 << 2);
    walk45DegFrames->append(QList<int>() << 6 << 1);

    Animation *walk45Deg = new Animation(spriteSheet, 48,48, walk45DegFrames, 250, true);

    movementAnims->append(walk45Deg);

    QList<QList<int>> *walk135DegFrames = new QList<QList<int>>();
    walk135DegFrames->append(QList<int>() << 14-6 << 0);
    walk135DegFrames->append(QList<int>() << 14-6 << 1);
    walk135DegFrames->append(QList<int>() << 14-6 << 2);
    walk135DegFrames->append(QList<int>() << 14-6 << 1);

    Animation *walk135Deg = new Animation(spriteSheetFlipped, 48,48, walk135DegFrames, 250, true);

    movementAnims->append(walk135Deg);

    QList<QList<int>> *walk270DegFrames = new QList<QList<int>>();
    walk135DegFrames->append(QList<int>() << 4 << 0);
    walk135DegFrames->append(QList<int>() << 4 << 1);
    walk135DegFrames->append(QList<int>() << 4 << 2);
    walk135DegFrames->append(QList<int>() << 4 << 1);

    Animation *walk270Deg = new Animation(spriteSheet, 48,48, walk270DegFrames, 250, true);

    movementAnims->append(walk270Deg);

    QList<QList<int>> *walk315DegFrames = new QList<QList<int>>();
    walk315DegFrames->append(QList<int>() << 3 << 0);
    walk315DegFrames->append(QList<int>() << 3 << 1);
    walk315DegFrames->append(QList<int>() << 3 << 2);
    walk315DegFrames->append(QList<int>() << 3 << 1);

    Animation *walk315Deg = new Animation(spriteSheet, 48,48, walk315DegFrames, 250, true);

    movementAnims->append(walk315Deg);

    QList<QList<int>> *walk225DegFrames = new QList<QList<int>>();
    walk225DegFrames->append(QList<int>() << 11 << 0);
    walk225DegFrames->append(QList<int>() << 11 << 1);
    walk225DegFrames->append(QList<int>() << 11 << 2);
    walk225DegFrames->append(QList<int>() << 11 << 1);

    Animation *walk225Deg = new Animation(spriteSheetFlipped, 48,48, walk225DegFrames, 250, true);

    movementAnims->append(walk225Deg);

    QList<QList<int>> *walk90DegFrames = new QList<QList<int>>();
    walk90DegFrames->append(QList<int>() << 0 << 0);
    walk90DegFrames->append(QList<int>() << 0 << 1);
    walk90DegFrames->append(QList<int>() << 0 << 2);
    walk90DegFrames->append(QList<int>() << 0 << 1);

    Animation *walk90Deg = new Animation(spriteSheetFlipped, 48,48, walk90DegFrames, 250, true);

    movementAnims->append(walk90Deg);

}

QRectF Footman::boundingRect() const
{
    return QRectF(6,6,36,36);
}
