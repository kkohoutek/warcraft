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
#include "entity/unit/Worker.hpp"
#include "ResourceManager.hpp"
#include "ui/PeasantUI.hpp"
#include "ui/HumanTownHallUI.hpp"
#include "ui/HumanBarracksUI.hpp"
#include "ui/Message.hpp"

class Warcraft : public QGraphicsView
{
public:
    Warcraft();
    ~Warcraft();

private:
    ResourceManager rm;
    Graph graph;
    Player *player;
    Player *enemy;

    QVector<Goldmine *>   goldmines;
    QVector<Trees *>      trees;

    QQueue<Entity *> garbage;

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

    void updateUIs();
    void updatePlayer(Player *p);

    void spawnUnit(Unit *u, Player *owner = nullptr);
    void spawnBuilding(Building *b, Player *owner = nullptr);
    void spawnGoldmine(Goldmine *g);

    void cleanUp();


    /* Postav hráči novou budovou za pomocí daného workera a vrať 0.
       Pokud není dost zlata vrátí 1.
       Pokud není dost dřeva vrátí 2.
       Pokud worker nepatří hráči, vrátí 3. */
    int newBuilding(Player *player, Building *building, Worker *worker);

    QLinkedList<Entity *> staticEntities() const;
    QLinkedList<Unit *>   allUnits() const;
    QLinkedList<Entity *> allEntities() const;

    // Specifikace nákladů pro každou budovu (pro gameplay)
    static QPair<int, int> cost(Building::Type type);


    /******************* UI STUFF **********************/
    Message message;

    bool isPressedLeftButton = false;
    QPoint position;
    QGraphicsRectItem *rect; // selection rect

    QWidget *currentUI = nullptr; // = null nebo jeden z následujících
    PeasantUI *peasantUI;
    HumanTownHallUI *hthUI;
    HumanBarracksUI *hbUI;

    void setUI(QWidget *ui);

    /******************* DEBUG STUFF *******************/
    size_t entitiesMemoryStatus() const;
};

#endif // WARCRAFT_HPP
