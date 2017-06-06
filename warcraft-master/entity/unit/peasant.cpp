#include "peasant.h"

Peasant::Peasant(QPointF pos) : Worker(pos)
{
setMaxHP(40);
setHP(40);
QPixmap *spriteSheet = new QPixmap(":graphics/PEASANT");
QPixmap *spriteSheetFlipped = new QPixmap(":graphics/PEASANT2");

//walk animations

movementAnims = new QList<Animation *>();

QList<QList<int>> *walk0DegFrames = new QList<QList<int>>();
walk0DegFrames->append(QList<int>() << 1 << 3);
walk0DegFrames->append(QList<int>() << 2 << 3);
walk0DegFrames->append(QList<int>() << 3 << 3);
walk0DegFrames->append(QList<int>() << 2 << 3);

Animation *walk0Deg = new Animation(spriteSheet, 32,32, walk0DegFrames, 250, true);

movementAnims->append(walk0Deg);

QList<QList<int>> *walk45DegFrames = new QList<QList<int>>();
walk45DegFrames->append(QList<int>() << 1 << 0);
walk45DegFrames->append(QList<int>() << 1 << 1);
walk45DegFrames->append(QList<int>() << 1 << 2);
walk45DegFrames->append(QList<int>() << 1 << 1);

Animation *walk45Deg = new Animation(spriteSheet, 32,32, walk45DegFrames, 250, true);

movementAnims->append(walk45Deg);

QList<QList<int>> *walk90DegFrames = new QList<QList<int>>();
walk90DegFrames->append(QList<int>() << 0 << 0);
walk90DegFrames->append(QList<int>() << 0 << 1);
walk90DegFrames->append(QList<int>() << 0 << 2);
walk90DegFrames->append(QList<int>() << 0 << 1);

Animation *walk90Deg = new Animation(spriteSheet, 32,32, walk90DegFrames, 250, true);

movementAnims->append(walk90Deg);

QList<QList<int>> *walk135DegFrames = new QList<QList<int>>();
walk135DegFrames->append(QList<int>() << 13 << 0);
walk135DegFrames->append(QList<int>() << 13 << 1);
walk135DegFrames->append(QList<int>() << 13 << 2);
walk135DegFrames->append(QList<int>() << 13 << 1);

Animation *walk135Deg = new Animation(spriteSheetFlipped, 32,32, walk135DegFrames, 250, true);

movementAnims->append(walk135Deg);

QList<QList<int>> *walk180DegFrames = new QList<QList<int>>();
walk180DegFrames->append(QList<int>() << 13 << 1);
walk180DegFrames->append(QList<int>() << 12 << 1);
walk180DegFrames->append(QList<int>() << 11 << 1);
walk180DegFrames->append(QList<int>() << 12 << 1);

Animation *walk180Deg = new Animation(spriteSheetFlipped, 32,32, walk180DegFrames, 250, true);

movementAnims->append(walk180Deg);

QList<QList<int>> *walk225DegFrames = new QList<QList<int>>();
walk225DegFrames->append(QList<int>() << 11 << 0);
walk225DegFrames->append(QList<int>() << 11 << 1);
walk225DegFrames->append(QList<int>() << 11 << 2);
walk225DegFrames->append(QList<int>() << 11 << 1);

Animation *walk225Deg = new Animation(spriteSheetFlipped, 32,32, walk225DegFrames, 250, true);

movementAnims->append(walk225Deg);

QList<QList<int>> *walk270DegFrames = new QList<QList<int>>();
walk270DegFrames->append(QList<int>() << 10 << 0);
walk270DegFrames->append(QList<int>() << 10 << 1);
walk270DegFrames->append(QList<int>() << 10 << 2);
walk270DegFrames->append(QList<int>() << 10 << 1);

Animation *walk270Deg = new Animation(spriteSheetFlipped, 32,32, walk270DegFrames, 250, true);

movementAnims->append(walk270Deg);

QList<QList<int>> *walk315DegFrames = new QList<QList<int>>();
walk315DegFrames->append(QList<int>() << 3 << 0);
walk315DegFrames->append(QList<int>() << 3 << 1);
walk315DegFrames->append(QList<int>() << 3 << 2);
walk315DegFrames->append(QList<int>() << 3 << 1);

Animation *walk315Deg = new Animation(spriteSheet, 32,32, walk315DegFrames, 250, true);

movementAnims->append(walk315Deg);

//minning
miningAnims = new QList<Animation *>();

QList<QList<int>> *mining0DegFrames = new QList<QList<int>>();
mining0DegFrames->append(QList<int>() << 3 << 0);
mining0DegFrames->append(QList<int>() << 3 << 1);
mining0DegFrames->append(QList<int>() << 3 << 2);
mining0DegFrames->append(QList<int>() << 3 << 1);

Animation *mining0Deg = new Animation(spriteSheet, 32,32, mining0DegFrames, 250, true);

miningAnims->append(mining0Deg);


setCurrentAnimation(walk315Deg);



}

QRectF Peasant::boundingRect() const
{
    return QRectF(6,6,36,36);
}
