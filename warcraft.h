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

protected:
    Player *player;
    Player *enemy;

    QList<Goldmine *>   *goldmines;
    QList<Trees *>      *trees;

    bool isPressedLeftButton = false;
    QPoint *position;
    QGraphicsRectItem *rect; // selection rect

    void loadBackground();
    void loadBuildings();
    void loadUnits();
    void loadWorld();
    void solveCollisions();

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    QList<Entity *> staticEntities();
    QList<Unit *> allUnits();
    QList<Entity *> allEntities();


};

#endif // WARCRAFT_H
