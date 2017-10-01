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
#include "ui/PeasantUI.hpp"

class Warcraft : public QGraphicsView
{
public:
    Player *player;
    Player *enemy;

    QList<Goldmine *>   goldmines;
    QList<Trees *>      trees;

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

    void spawnUnit(Unit *u, Player *owner = nullptr);
    void spawnBuilding(Building *b, Player *owner = nullptr);
    void spawnGoldmine(Goldmine *g);

    QList<Entity *> staticEntities() const;
    QList<Unit *>   allUnits() const;
    QList<Entity *> allEntities() const;
    QList<Entity *> deadEntities() const;

    void printGameInfo();

    static int costGold(Building::Type type);
    static int costLumber(Building::Type type);

protected:
    ResourceManager *rm;
    Graph graph;

    // ui stuff
    bool isPressedLeftButton = false;
    QPoint position;
    QGraphicsRectItem *rect; // selection rect

    //QWidget *currentUI = nullptr;
    PeasantUI *peasantUI;
    Building *currentBuilding = nullptr;

    // costs
    //QMap<Building::Type, QPair<int, int>> buildingCosts;

};

#endif // WARCRAFT_HPP
