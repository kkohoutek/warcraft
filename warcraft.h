#ifndef WARCRAFT_H
#define WARCRAFT_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include "player.h"


class Warcraft : public QGraphicsView
{
public:
    Warcraft();
    ~Warcraft();

    void loadBackground();
    void loadBuildings();

    void timerEvent(QTimerEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void newBuilding(Building *building, Worker *worker, Player *player, int costGold, int costLumber);



private:
    Player *player;
    Player *enemy;

};

#endif // WARCRAFT_H
