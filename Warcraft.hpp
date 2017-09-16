#ifndef WARCRAFT_HPP
#define WARCRAFT_HPP

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QRectF>
#include <QRect>
#include <QGraphicsRectItem>
#include "Player.hpp"
#include "entity/Goldmine.hpp"
#include "pathfinding.hpp"
#include "ResourceManager.hpp"

class Warcraft : public QGraphicsView
{
public:
    Warcraft();
    ~Warcraft();

    void initResources();
    void loadBuildings();
    void loadUnits();
    void loadWorld();

    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    QList<Entity *> staticEntities() const;
    QList<Unit *>   allUnits() const;
    QList<Entity *> allEntities() const;

private:
    ResourceManager *rm;

    Player *player;
    Player *enemy;

    QList<Goldmine *>   goldmines;
    QList<Trees *>      trees;

    bool isPressedLeftButton = false;
    QPoint position;
    QGraphicsRectItem *rect; // selection rect

    Graph graph;
};

#endif // WARCRAFT_HPP
