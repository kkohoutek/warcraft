#include "warcraft.h"

#include <QGraphicsScene>
#include <QScrollBar>
#include <QDebug>
#include <QPainter>
#include <QOpenGLWidget>
#include <QGraphicsSimpleTextItem>

#include "entity/entity.h"
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

#include "pathfinding/bfs.h"


Warcraft::Warcraft()
{
    //setViewport(new QOpenGLWidget(this)); // paintEvent = blackscreen
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMouseTracking(true);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,2048,2048);
    setScene(scene);

    rect = new QGraphicsRectItem();
    centerOn(0,0);

    player = new Player(HUMAN);
    player->addFood(8);
    player->addLumber(10000);

    enemy = new Player(ORC);

    player_gc = new GarbageCollector(player, 15000);
    //enemy_gc = new GarbageCollector(enemy, 2000);


    loadBackground();
    loadWorld();
    loadUnits();
    loadBuildings();

    startTimer(17);


    // test pathfinding


}

Warcraft::~Warcraft() {

    for(Goldmine *g : goldmines){
        delete g;
    }
    /*
    for(Trees *t : trees){
        delete t;
    }*/

    delete rect;
    delete player;
    delete enemy;
    delete player_gc;

}

void Warcraft::loadBackground()
{
    QRect rect(3*32, 0, 32, 32);
    QImage original(":graphics/WORLD");
    QImage cropped = original.copy(rect);
    QBrush brush(cropped);
    brush.setStyle(Qt::TexturePattern);
    scene()->setBackgroundBrush(brush);

}

void Warcraft::loadBuildings() {
    Building *th = new HumanTownHall(QPointF(216,216), true, res);
    player->getBuildings().append(th);
    scene()->addItem(th);

    th = new OrcTownHall(QPointF(2048-300,2048-300), true, res);
    enemy->getBuildings().append(th);
    scene()->addItem(th);

}

void Warcraft::loadUnits(){
    for(int i = 0; i < 4; i++){
        Worker *w = new Worker(QPointF(128+i*28,128), player->getRace(), player->getGold(), player->getLumber(), res);
        player->getWorkers().append(w);
        scene()->addItem(w);
    }

    Footman *f = new Footman(QPointF(192,144), res);
    scene()->addItem(f);
    player->getUnits().append(f);

    //f->die();


    for(int i = 0; i < 4; i++){
        Grunt *g = new Grunt(QPointF(2048-420+i*40, 2048-286-i*40), res);
        scene()->addItem(g);
        enemy->getUnits().append(g);
    }

}

void Warcraft::loadWorld() {
    Goldmine *a = new Goldmine(QPointF(64,64), res);
    Goldmine *b = new Goldmine(QPointF(2048-128, 2048-128), res);
    scene()->addItem(a);
    scene()->addItem(b);

    goldmines.append(a);
    goldmines.append(b);

}

void Warcraft::solveCollisions() {

    for(Entity *e : staticEntities()){
        for(Unit *u : player->allUnits()){
            if(e->collidesWithItem(u) && !static_cast<Worker *>(u)->isGatheringGold()){
                u->stopMoving();
                u->moveBy(u->getSpeed() * -u->direction().x(), u->getSpeed() * -u->direction().y());
            }
        }
        for(Unit *u : enemy->allUnits()){
            if(e->collidesWithItem(u) && !static_cast<Worker *>(u)->isGatheringGold()){
                u->stopMoving();
                u->moveBy(u->getSpeed() * -u->direction().x(), u->getSpeed() * -u->direction().y());
            }
        }

    }
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

    //solveCollisions();

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

        for(Unit *unit : player->allUnits()){
            if(unit->boundingRect().translated(unit->pos()).contains(actualPos) && unit->isAlive()){
                player->selectUnit(unit);
            }
        }

    } else if (event->button() == Qt::RightButton){
        Unit *u = player->getSelectedUnits().at(0);
        Graph *graph = generateGraphForPathfinding();
        BFS *bfs = new BFS(graph, graph->getNodeByPos(48,48), graph->getNodeByPos(48*6,48*12));
        QList<QPointF> path = bfs->shortestPath();

        u->setPath(path);
        u->move();

        //delete bfs;
        //delete graph;
        //player->selectedMoveTo(actualPos,40);

        for(Goldmine *g : goldmines){
            if(g->boundingRect().translated(g->pos()).contains(actualPos)){
                QList<Worker *> sw = player->selectedWorkers();
                if(!sw.empty()){
                    for(Worker *w : sw){
                        //w->cancel();
                        w->gatherGold(g, player->goldDestination());
                        w->setTarget(g);
                        w->move();
                    }
                }
            }
        }
    }
}

void Warcraft::mouseReleaseEvent(QMouseEvent *releaseEvent)
{
    if(releaseEvent->button() == Qt::LeftButton){

        isPressedLeftButton = false;

        QList<Unit *> selected;
        for(Unit *unit : player->allUnits()){
            if(rect->rect().contains(unit->boundingRect().translated(unit->pos()).center()) && unit->isAlive() && unit->isVisible()){
                selected.append(unit);
            }
        }
        player->selectUnits(selected);

        if(scene()->items().contains(rect)){
            scene()->removeItem(rect);
        }
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
    QList<Worker *> sw = player->selectedWorkers();
    switch(event->key()){
    case Qt::Key_Escape:
        window()->close();
        break;
    case Qt::Key_B:

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
    for(Worker *w : player->getWorkers()){
        allUnits.append(w);
    }
    for(Worker *w : enemy->getWorkers()){
        allUnits.append(w);
    }
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

Graph *Warcraft::generateGraphForPathfinding() const {
    // not optimized

    Graph *graph = new Graph();

    qreal width = scene()->sceneRect().width();
    qreal height = scene()->sceneRect().height();
    int gap = 48;


    for(int i = 0; i < height; i+=gap){
        for(int j = 0; j < width; j+=gap){
            for(Entity *entity : staticEntities()){
                if(!entity->boundingRect().translated(entity->pos()).contains(j,i)){
                    graph->addNode(j, i);
                    qDebug() << graph->getNodes().size();

                }
            }

        }
    }

    for(Node *a : graph->getNodes()){
        for(Node *b : graph->getNodes()){
            if(QLineF(a->pos,b->pos).length() == gap){
               // qDebug() << *a->pos << *b->pos;
                if(a->getNeighbors().size() == 4){
                    break;
                } else {
                    a->addNeighbor(b);
                    b->addNeighbor(a);
                }

            }
        }
    }

    for(Node *n : graph->getNodes()){

    //qDebug() << *n->pos;
    /*
        QGraphicsSimpleTextItem *l = new QGraphicsSimpleTextItem(QString::number(n->pos->x()) + ", " + QString::number(n->pos->y()));
        l->setPos(n->pos->x(),n->pos->y());
        l->setScale(0.85);
        scene()->addItem(l);*/
    }


    return graph;


}


void Warcraft::paintEvent(QPaintEvent *event) {
    QGraphicsView::paintEvent(event); 
    QPainter painter(viewport());
    painter.setFont(QFont("sans-serif",10));
    painter.setPen(Qt::white);
    painter.drawText(QPointF(700, 20), QString("FOOD: "+QString::number(player->getFood())+"   GOLD: "+QString::number(player->getGold())+"   LUMBER: "+QString::number(player->getLumber())));

}

