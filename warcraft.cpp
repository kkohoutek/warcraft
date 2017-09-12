#include "warcraft.h"

#include <QGraphicsScene>
#include <QScrollBar>
#include <QDebug>
#include <QPainter>

#include "entity/building/humanfarm.h"
#include "entity/building/humanblacksmith.h"
#include "entity/building/humanchurch.h"
#include "entity/building/humanbarracks.h"
#include "entity/building/humanstables.h"
#include "entity/building/humantownhall.h"
#include "entity/building/humanlumbermill.h"
#include "entity/building/humantower.h"
#include "entity/unit/footman.h"
#include "entity/building/orcbarracks.h"
#include "entity/building/orcblacksmith.h"
#include "entity/building/orcfarm.h"
#include "entity/building/orckennels.h"
#include "entity/building/orclumbermill.h"
#include "entity/building/orctemple.h"
#include "entity/building/orctower.h"
#include "entity/building/orctownhall.h"
#include "entity/trees.h"
#include "entity/unit/grunt.h"
#include "pathfinding.h"

#define MAP_SIZE 2048

Warcraft::Warcraft() {
    initResources();

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMouseTracking(true);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,MAP_SIZE,MAP_SIZE);
    setScene(scene);
    centerOn(0,0);

    rect = new QGraphicsRectItem();

    player = new Player(HUMAN);
    player->food += 8;
    player_gc = new GarbageCollector(player, 15000);

    enemy = new Player(ORC);

    scene->setBackgroundBrush(QBrush(*(rm->getSprite("MAP1"))));
    loadWorld();
    loadUnits();
    loadBuildings();

    graph.update(staticEntities());

    startTimer(18);
}

Warcraft::~Warcraft() {
    qDeleteAll(goldmines);
    qDeleteAll(trees);
    delete rect;
    delete player;
    delete enemy;
    delete player_gc;
    delete rm;
}

void Warcraft::loadBuildings() {
    Building *th = new HumanTownHall(QPointF(216,216), true, rm);
    player->getBuildings().append(th);
    scene()->addItem(th);

    th = new HumanFarm(QPointF(70, 262), true, rm, &(player->food));
    player->getBuildings().append(th);
    scene()->addItem(th);

    th = new HumanFarm(QPointF(310, 290), true, rm, &(player->food));
    player->getBuildings().append(th);
    scene()->addItem(th);

    th = new HumanChurch(QPointF(278, 81), false, rm);
    player->getBuildings().append(th);
    scene()->addItem(th);
    th->startConstruction();

    th = new HumanBarracks(QPointF(220, 400), true, rm);
    player->getBuildings().append(th);
    scene()->addItem(th);

    th = new OrcTownHall(QPointF(MAP_SIZE-300,MAP_SIZE-300), true, rm);
    enemy->getBuildings().append(th);
    scene()->addItem(th);

}

void Warcraft::loadUnits(){
    for(int i = 0; i < 4; i++){
        Worker *w = new Worker(QPointF(128+i*28,128), PEASANT, &(player->gold), &(player->lumber), &graph, rm);
        player->getUnits().append(w);
        scene()->addItem(w);
    }

    Footman *f = new Footman(QPointF(500,120), rm);
    scene()->addItem(f);
    player->getUnits().append(f);

    for(int i = 0; i < 4; i++){
        Grunt *g = new Grunt(QPointF(MAP_SIZE-420+i*40, MAP_SIZE-286-i*40), rm);
        scene()->addItem(g);
        enemy->getUnits().append(g);
    }

}

void Warcraft::loadWorld() {
    Goldmine *g = new Goldmine(QPointF(64,64), rm);
    scene()->addItem(g);
    goldmines.append(g);
    g = new Goldmine(QPointF(MAP_SIZE-192, MAP_SIZE-192), rm);
    scene()->addItem(g);
    goldmines.append(g);
    g = new Goldmine(QPointF(800,522), rm);
    scene()->addItem(g);
    goldmines.append(g);
}

void Warcraft::timerEvent(QTimerEvent *event) {
    QPoint p = mapFromGlobal(QCursor::pos());
    if(p.x() >=  window()->width() - 50 && p.x() <= window()->width() && p.y() >= 0 && p.y() <= window()->height() ){
        horizontalScrollBar()->setValue(horizontalScrollBar()->value()+20);
    }
    else if(p.x() <= 50 && p.x() >= 0 && p.y() <= window()->height() && p.y() >= 0){
        horizontalScrollBar()->setValue(horizontalScrollBar()->value()-20);
    }

    if(p.y() >=  window()->height() - 50 && p.y() <= window()->height() && p.x() >= 0 && p.x() <= window()->width() ){
        verticalScrollBar()->setValue(verticalScrollBar()->value()+20);
    }
    else if(p.y() <= 50 && p.y() >= 0 && p.x() <= window()->width() && p.x() >= 0){
         verticalScrollBar()->setValue(verticalScrollBar()->value()-20);
    }

    player->update();
    enemy->update();

    viewport()->update();

    Q_UNUSED(event);
}

void Warcraft::mousePressEvent(QMouseEvent *event){

    QPointF actualPos = mapToScene(mapFromGlobal(QCursor::pos()));
    if(event->button() == Qt::LeftButton){
        isPressedLeftButton = true;
        position.setX(actualPos.x());
        position.setY(actualPos.y());

        for(Unit *unit : player->getUnits()){
            if(unit->boundingRect2().contains(actualPos) && unit->isAlive()){
                player->selectUnit(unit);
            }
        }
    } else if (event->button() == Qt::RightButton){

        for(int i = 0; i < player->getSelectedUnits().size(); i++){
            Unit *u = player->getSelectedUnits()[i];
            auto path = bfs::shortestPath(graph, u->center(), actualPos+QPointF(i*32, 0));
            if(!path.isEmpty()){
                u->setPath(path);
                u->move();
            }
        }

        // Klikl hráč na goldmine?
        for(Goldmine *g : goldmines){
            if(g->boundingRect2().contains(actualPos)){
                for(Unit *u : player->getSelectedUnits()){
                    if(u->getType() == PEASANT) {
                        Worker *w = static_cast<Worker *>(u);
                        w->mine(g, player->getBuildings()[0]);
                    }
                }
            }
        }
    }

    QGraphicsView::mousePressEvent(event);
}

void Warcraft::mouseReleaseEvent(QMouseEvent *releaseEvent) {
    if(releaseEvent->button() == Qt::LeftButton){
        isPressedLeftButton = false;

        QList<Unit *> selected;
        for(Unit *unit : player->getUnits()){
            if(rect->rect().intersects(unit->boundingRect2()) && unit->isAlive() && unit->isVisible()){
                selected.append(unit);
            }
        }
        player->selectUnits(selected);

        if(scene()->items().contains(rect)) scene()->removeItem(rect);
    }
}


void Warcraft::mouseMoveEvent(QMouseEvent *event) {
    if(isPressedLeftButton){
        if(scene()->items().contains(rect)){
            scene()->removeItem(rect);
        }
        QPointF actualPos = mapToScene(mapFromGlobal(QCursor::pos()));
        rect->setPen(QPen(Qt::green));
        rect->setRect(position.x(), position.y(),actualPos.x() -position.x() , actualPos.y()-position.y());

        scene()->addItem(rect);
    }

    Q_UNUSED(event);
}

void Warcraft::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Escape:
        window()->close();
        break;

    case Qt::Key_B:
        player->newBuilding(new HumanChurch(QPointF(550,550), false, rm), static_cast<Worker *>(player->getUnits()[0]), 0, 0);
        graph.update(staticEntities());
        break;
    }

}

QList<Entity *> Warcraft::staticEntities() const {
    QList<Entity *> list;
    for(Building *b : player->getBuildings()){
        list.append(b);
    }
    for(Building *b : enemy->getBuildings()){
        list.append(b);
    }
    for(Goldmine *g : goldmines){
        list.append(g);
    }
    return list;
}

QList<Unit *> Warcraft::allUnits() const {
    QList<Unit *> allUnits;
    allUnits.append(player->getUnits());
    allUnits.append(enemy->getUnits());
    return allUnits;
}

QList<Entity *> Warcraft::allEntities() const {
    QList<Entity *> allEntities;
    allEntities.append(staticEntities());

    for(Unit *u : allUnits()){
        allEntities.append(u);
    }
    return allEntities;
}


void Warcraft::paintEvent(QPaintEvent *event) {
    QGraphicsView::paintEvent(event); 
    QPainter painter(viewport());
    painter.setFont(QFont("sans-serif",10));
    painter.setPen(Qt::white);
    painter.drawText(QPointF(700, 20), QString("FOOD: "+QString::number(player->food)+"   GOLD: "+QString::number(player->gold)+"   LUMBER: "+QString::number(player->lumber)));

     // visualize graph
    /*
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *n = graph.nodes[i][j];
            if(n){
                painter.drawEllipse(mapFromScene(n->pos), 1, 1);
            }
        }
    }*/
}

void Warcraft::initResources() {
    rm = new ResourceManager();
    rm->loadSprite("ICONS", new QPixmap(":graphics/ICONS"));
    rm->loadSprite("MAP1", new QPixmap(":graphics/MAP1"));
    rm->loadSprite("BUILDINGS_H", new QPixmap(":graphics/BUILDINGS_H"));
    rm->loadSprite("BUILDINGS_O", new QPixmap(":graphics/BUILDINGS_O"));
    rm->loadSprite("FOOTMAN", new QPixmap(":graphics/FOOTMAN"));
    rm->loadSprite("GRUNT", new QPixmap(":graphics/GRUNT"));
    rm->loadSprite("DAEMON", new QPixmap(":graphics/DAEMON"));
    rm->loadSprite("PEASANT", new QPixmap(":graphics/PEASANT"));
    rm->loadSprite("MISC", new QPixmap(":graphics/MISC"));
    rm->loadSprite("WORLD", new QPixmap(":graphics/WORLD"));
    rm->copySprite("PEASANT", "PEASANT_flipped", true, false);
    rm->copySprite("FOOTMAN", "FOOTMAN_flipped", true, false);
    rm->copySprite("GRUNT", "GRUNT_flipped", true, false);
    rm->copySprite("DAEMON", "DAEMON_flipped", true, false);

}

