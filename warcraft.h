#ifndef WARCRAFT_H
#define WARCRAFT_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QRectF>
#include <QRect>
#include <QGraphicsRectItem>
#include "player.h"


class Warcraft : public QGraphicsView
{
public:
    Warcraft();
    ~Warcraft();

    void loadBackground();
    void loadBuildings();

    void timerEvent(QTimerEvent *event);

    bool isPressedLeftButton = false;
    QPoint *position;
    QGraphicsRectItem *rect; // selection rect

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void mouseMoveEvent(QMouseEvent *event);


private:
    Player *player;
    Player *enemy;

};

#endif // WARCRAFT_H
