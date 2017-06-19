#include "warcraft.h"

#include <QGraphicsScene>
#include <QScrollBar>
#include <QDebug>
#include <QPainter>
#include <QOpenGLWidget>

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
#include  "entity/building/orcbarracks.h"
#include  "entity/building/orcblacksmith.h"
#include  "entity/building/orcfarm.h"
#include  "entity/building/orckennels.h"
#include  "entity/building/orclumbermill.h"
#include  "entity/building/orctemple.h"
#include  "entity/building/orctower.h"
#include  "entity/building/orctownhall.h"
#include "entity/trees.h"
#include "entity/unit/grunt.h"


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
    position = new QPoint();

    player = new Player(HUMAN);
    player->addFood(4);

    enemy = new Player(ORC);


    loadBackground();
    loadWorld();
    loadUnits();
    loadBuildings();

    startTimer(17);

}

Warcraft::~Warcraft() {
    for(Goldmine *g : *goldmines){
        delete g;
    }
    /*
    for(Trees *t : *trees){
        delete t;
    }*/
    delete trees;
    delete goldmines;
    delete rect;
    delete position;
    delete player;
    delete enemy;
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
    Building *th = new HumanTownHall(QPointF(216,216), true);
    player->getBuildings().append(th);
    scene()->addItem(th);

    th = new OrcTownHall(QPointF(2048-300,2048-300), true);
    enemy->getBuildings().append(th);
    scene()->addItem(th);

}

void Warcraft::loadUnits(){
    for(int i = 0; i < 4; i++){
        Worker *w = new Worker(QPointF(128+i*28,128), player->getRace(), player->getGold(), player->getLumber());
        player->getWorkers().append(w);
        scene()->addItem(w);
    }

    Footman *f = new Footman(QPointF(112,138));
    scene()->addItem(f);
    player->getUnits().append(f);


    for(int i = 0; i < 4; i++){
        Grunt *g = new Grunt(QPointF(2048-420+i*40, 2048-286-i*40));
        scene()->addItem(g);
        enemy->getUnits().append(g);
    }
}

void Warcraft::loadWorld() {
    goldmines = new QList<Goldmine *>();
    Goldmine *a = new Goldmine(QPointF(64,64));
    Goldmine *b = new Goldmine(QPointF(2048-128, 2048-128));
    scene()->addItem(a);
    scene()->addItem(b);

    goldmines->append(a);
    goldmines->append(b);

}

void Warcraft::solveCollisions() {

    for(Entity *e : staticEntities()){

        for(Worker *w : player->getWorkers()){
            if(e->collidesWithItem(w) && !w->isGatheringGold()){
                w->stopMoving();
                w->moveBy(w->getSpeed() * -w->direction().x(), w->getSpeed() * -w->direction().y());
            }
        }
        for(Unit *u : player->getUnits()){
            if(e->collidesWithItem(u) && u->isMoving()){
                u->stopMoving();
                u->moveBy(u->getSpeed() * -u->direction().x(), u->getSpeed() * -u->direction().y());
            }
        }
        for(Worker *w : enemy->getWorkers()){
            if(e->collidesWithItem(w) && !w->isGatheringGold()){
                w->stopMoving();
                w->moveBy(w->getSpeed() * -w->direction().x(), w->getSpeed() * -w->direction().y());
            }
        }
        for(Unit *u : enemy->getUnits()){
            if(e->collidesWithItem(u) && u->isMoving()){
                u->stopMoving();
                u->moveBy(u->getSpeed() * -u->direction().x(), u->getSpeed() * -u->direction().y());
            }
        }

    }
}

void Warcraft::timerEvent(QTimerEvent *event) {
    QPoint p = mapFromGlobal(QCursor::pos());
    if(p.x() >= this->window()->width() - 50 && p.x() <= this->window()->width() && p.y() >= 0 && p.y() <= this->window()->height() ){
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()+20);


    }
    else if(p.x() <= 50 && p.x() >= 0 && p.y() <= this->window()->height() && p.y() >= 0){
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()-20);

    }

    if(p.y() >= this->window()->height() - 50 && p.y() <= this->window()->height() && p.x() >= 0 && p.x() <= this->window()->width() ){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()+20);

    }

    else if(p.y() <= 50 && p.y() >= 0 && p.x() <= this->window()->width() && p.x() >= 0){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()-20);

    }

    solveCollisions();

    player->update();
    enemy->update();

    viewport()->update();

    Q_UNUSED(event);
}

void Warcraft::mousePressEvent(QMouseEvent *event){

    QPointF actualPos = mapToScene(mapFromGlobal(QCursor::pos()));
    if(event->button() == Qt::LeftButton){
        isPressedLeftButton = true;
        position->setX(actualPos.x());
        position->setY(actualPos.y());


        for(Unit *unit : player->allUnits()){
            if(unit->boundingRect().translated(unit->pos()).contains(actualPos)){
                player->selectUnit(unit);
            }
        }

    } else if (event->button() == Qt::RightButton){
        player->selectedMoveTo(actualPos,40);

        for(Goldmine *g : *goldmines){
            if(g->boundingRect().translated(g->pos()).contains(actualPos)){
                QList<Worker *> sw = player->selectedWorkers();
                if(!sw.empty()){
                    for(Worker *w : sw){
                        //w->cancel();
                        w->gatherGold(g, player->getBuildings().at(0));
                        w->setTarget(g->center());
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
            if(rect->rect().contains(unit->boundingRect().translated(unit->pos()).center())){
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
        rect->setRect(position->x(), position->y(),actualPos.x() -position->x() , actualPos.y()-position->y());

        scene()->addItem(rect);
    }

    Q_UNUSED(event);
}

void Warcraft::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Escape:
        window()->close();
        break;
    }

}


QList<Entity *> Warcraft::staticEntities() const {
    QList<Entity *> list;
    for(Building *b : player->getBuildings()){
        list.append(b);
    }
    for(Goldmine *g : *goldmines){
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



void Warcraft::paintEvent(QPaintEvent *event)
{

    QGraphicsView::paintEvent(event);
    QPainter painter(viewport());
    painter.setFont(QFont("sans-serif",10));
    painter.setPen(Qt::white);
    painter.drawText(QPointF(700, 20), QString("FOOD: "+QString::number(player->getFood())+"   GOLD: "+QString::number(player->getGold())+"   LUMBER: "+QString::number(player->getLumber())));

}

