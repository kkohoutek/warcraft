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
#include "garbagecollector.h"
#include "pathfinding/graph.h"
#include "resourcemanager.h"

class Warcraft : public QGraphicsView
{
public:
    Warcraft();
    ~Warcraft();

protected:
    ResourceManager* rm;

    Player *player;
    Player *enemy;

    GarbageCollector *player_gc;
    GarbageCollector *enemy_gc;

    QList<Goldmine *>   goldmines;
    QList<Trees *>      trees;

    bool isPressedLeftButton = false;
    QPoint position;
    QGraphicsRectItem *rect; // selection rect

    Graph *graph;

    void initResources();
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

    QList<Entity *> staticEntities() const;
    QList<Unit *> allUnits() const;
    QList<Entity *> allEntities() const;

    Graph *generateGraphForPathfinding() const;


};

#endif // WARCRAFT_H
