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
#include "ResourceManager.hpp"
#include "ui/PeasantUI.hpp"
#include "ui/Message.hpp"

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

    /* Postav hráči novou budovou za pomocí daného workera a vrať 0.
       Pokud není dost zlata vrátí 1.
       Pokud není dost dřeva vrátí 2.
       Pokud worker nepatří hráči, vrátí 3. */
    int newBuilding(Player *player, Building *building, Worker *worker);

    QList<Entity *> staticEntities() const;
    QList<Unit *>   allUnits() const;
    QList<Entity *> allEntities() const;
    QList<Entity *> deadEntities() const;

    void printGameInfo();

    // Specifikace nákladů pro každou budovu (pro gameplay)
    static QPair<int, int> cost(Building::Type type);

protected:
    ResourceManager *rm;
    Graph graph;

    /******************* UI STUFF **********************/
    Message message;

    bool isPressedLeftButton = false;
    QPoint position;
    QGraphicsRectItem *rect; // selection rect

    //QWidget *currentUI = nullptr;
    PeasantUI *peasantUI;
    Building *currentBuilding = nullptr;
};

#endif // WARCRAFT_HPP
