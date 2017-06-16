#ifndef WARCRAFT_H
#define WARCRAFT_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QRectF>
#include <QRect>
#include <QGraphicsRectItem>
#include "player.h"
#include "entity/goldmine.h"
#include <QGraphicsSimpleTextItem>

class Warcraft : public QGraphicsView
{
public:
    Warcraft();
    ~Warcraft();

    void loadBackground();
    void loadBuildings();
    void loadUnits();
    void loadWorld();
    void solveCollisions();

    void timerEvent(QTimerEvent *event);

    bool isPressedLeftButton = false;
    QPoint *position;
    QGraphicsRectItem *rect; // selection rect

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void mouseMoveEvent(QMouseEvent *event);

    QList<Entity *> staticEntities();
    QList<Unit *> allUnits();


private:
    Player *player;
    Player *enemy;

    QList<Goldmine *>   *goldmines;
    QList<Trees *>      *trees;
    void paintEvent(QPaintEvent *event);

};

#endif // WARCRAFT_H
