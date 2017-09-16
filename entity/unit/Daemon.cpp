#include "Daemon.hpp"

Daemon::Daemon(QPointF pos, ResourceManager *rm) : Unit(pos, DAEMON, 1,65,0,0)
{
    setMaxHP(300);
    setHP(300);

    QPixmap *spriteSheet = rm->getSprite("DAEMON");
        QPixmap *spriteSheetFlipped = rm->getSprite("DAEMON_flipped");

        QList<QList<int>> walk0DegFrames;
        walk0DegFrames.append(QList<int>() << 2 << 0);
        walk0DegFrames.append(QList<int>() << 2 << 1);
        walk0DegFrames.append(QList<int>() << 2 << 2);
        walk0DegFrames.append(QList<int>() << 2 << 1);

        Animation *walk0Deg = new Animation(spriteSheet, 48,48, walk0DegFrames, 250, true);

        movementAnims.append(walk0Deg);

        QList<QList<int>> walk45DegFrames;
        walk45DegFrames.append(QList<int>() << 1 << 0);
        walk45DegFrames.append(QList<int>() << 1 << 1);
        walk45DegFrames.append(QList<int>() << 1 << 2);
        walk45DegFrames.append(QList<int>() << 1 << 1);

        Animation *walk45Deg = new Animation(spriteSheet, 48,48, walk45DegFrames, 250, true);

        movementAnims.append(walk45Deg);

        QList<QList<int>> walk90DegFrames;
        walk90DegFrames.append(QList<int>() << 0 << 0);
        walk90DegFrames.append(QList<int>() << 0 << 1);
        walk90DegFrames.append(QList<int>() << 0 << 2);
        walk90DegFrames.append(QList<int>() << 0 << 1);

        Animation *walk90Deg = new Animation(spriteSheet, 48,48, walk90DegFrames, 250, true);

        movementAnims.append(walk90Deg);

        QList<QList<int>> walk135DegFrames;
        walk135DegFrames.append(QList<int>() << 13 << 0);
        walk135DegFrames.append(QList<int>() << 13 << 1);
        walk135DegFrames.append(QList<int>() << 13 << 2);
        walk135DegFrames.append(QList<int>() << 13 << 1);

        Animation *walk135Deg = new Animation(spriteSheetFlipped, 48,48, walk135DegFrames, 250, true);

        movementAnims.append(walk135Deg);

        QList<QList<int>> walk180DegFrames;
        walk180DegFrames.append(QList<int>() << 12 << 0);
        walk180DegFrames.append(QList<int>() << 12 << 1);
        walk180DegFrames.append(QList<int>() << 12 << 2);
        walk180DegFrames.append(QList<int>() << 12 << 1);

        Animation *walk180Deg = new Animation(spriteSheetFlipped, 48,48, walk180DegFrames, 250, true);

        movementAnims.append(walk180Deg);

        QList<QList<int>> walk225DegFrames;
        walk225DegFrames.append(QList<int>() << 11 << 0);
        walk225DegFrames.append(QList<int>() << 11 << 1);
        walk225DegFrames.append(QList<int>() << 11 << 2);
        walk225DegFrames.append(QList<int>() << 11 << 1);

        Animation *walk225Deg = new Animation(spriteSheetFlipped, 48,48, walk225DegFrames, 250, true);

        movementAnims.append(walk225Deg);

        QList<QList<int>> walk270DegFrames;
        walk270DegFrames.append(QList<int>() << 3 << 0);
        walk270DegFrames.append(QList<int>() << 3 << 1);
        walk270DegFrames.append(QList<int>() << 3 << 2);
        walk270DegFrames.append(QList<int>() << 3 << 1);

        Animation *walk270Deg = new Animation(spriteSheet, 48,48, walk270DegFrames, 250, true);

        movementAnims.append(walk270Deg);

        QList<QList<int>> walk315DegFrames;
        walk315DegFrames.append(QList<int>() << 2 << 0);
        walk315DegFrames.append(QList<int>() << 2 << 1);
        walk315DegFrames.append(QList<int>() << 2 << 2);
        walk315DegFrames.append(QList<int>() << 2 << 1);

        Animation *walk315Deg = new Animation(spriteSheet, 48,48, walk315DegFrames, 250, true);

        movementAnims.append(walk315Deg);


        //atack animations

        QList<QList<int>> attack0DegFrames;
        attack0DegFrames.append(QList<int>() << 7 << 1);
        attack0DegFrames.append(QList<int>() << 7 << 0);
        attack0DegFrames.append(QList<int>() << 7 << 4);
        attack0DegFrames.append(QList<int>() << 7 << 0);
        attack0DegFrames.append(QList<int>() << 7 << 1);

        Animation *attack0Deg = new Animation(spriteSheet, 48,48, attack0DegFrames, 250, true);

        attackAnims.append(attack0Deg);

        QList<QList<int>> attack45DegFrames;
        attack45DegFrames.append(QList<int>() << 6 << 2);
         attack45DegFrames.append(QList<int>() << 6 << 3);
        attack45DegFrames.append(QList<int>() << 6 << 4);
         attack45DegFrames.append(QList<int>() << 6 << 3);
         attack45DegFrames.append(QList<int>() << 6 << 2);

        Animation *attack45Deg = new Animation(spriteSheet, 48,48, attack45DegFrames, 250, true);

        attackAnims.append(attack45Deg);

        QList<QList<int>> attack90DegFrames;
        attack90DegFrames.append(QList<int>() << 5 << 0);
        attack90DegFrames.append(QList<int>() << 5 << 2);
        attack90DegFrames.append(QList<int>() << 5 << 4);
        attack90DegFrames.append(QList<int>() << 5 << 0);

        Animation *attack90Deg = new Animation(spriteSheet, 48,48, attack90DegFrames, 250, true);

        attackAnims.append(attack90Deg);

        QList<QList<int>> attack135DegFrames;
        attack135DegFrames.append(QList<int>() << 8 << 2);
        attack135DegFrames.append(QList<int>() << 8 << 3);
        attack135DegFrames.append(QList<int>() << 8 << 4);
         attack135DegFrames.append(QList<int>() << 8 << 3);
        attack135DegFrames.append(QList<int>() << 8 << 2);

        Animation *attack135Deg = new Animation(spriteSheetFlipped, 48,48, attack135DegFrames, 250, true);

        attackAnims.append(attack135Deg);



    //test
        setCurrentAnimation(attack135Deg);
    getCurrentAnimation()->start();



}

QRectF Daemon::boundingRect() const
{
    return QRectF(32,32,48,48);
}
