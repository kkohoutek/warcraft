#include "warcraft.h"
#include "entity/entity.h"
#include "animation.h"

#include <QGraphicsScene>
#include <QScrollBar>
#include <QDebug>
#include <QPainter>
#include <QTextItem>
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


Warcraft::Warcraft()
{
    this->verticalScrollBar()->hide();
    this->horizontalScrollBar()->hide();
    setMouseTracking(true);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,2048,2048);
    setScene(scene);

    rect = new QGraphicsRectItem();
    position = new QPoint();

    player.addGold(10000);
    player.addLumber(10000);
    player.addFood(10000);


    loadBackground();
    loadWorld();
    loadUnits();
    loadBuildings();

    startTimer(17);
    goldText = new QGraphicsSimpleTextItem();

}

Warcraft::~Warcraft() {
    for(Goldmine *g : *goldmines){
        delete g;
    }
    delete goldmines;
    delete rect;
    delete position;
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
    player.getBuildings().append(th);
    scene()->addItem(th);
    Building *tho = new OrcTownHall(QPointF(600,216), true);
    player.getBuildings().append(tho);
    scene()->addItem(tho);


}

void Warcraft::loadUnits(){
    for(int i = 0; i < 4; i++){
        Worker *w = new Worker(QPointF(128+i*28,128), player.getRace());
        player.getWorkers().append(w);
        scene()->addItem(w);
    }

    Footman *f = new Footman(QPointF(112,138));
    scene()->addItem(f);
    player.getUnits().append(f);
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
    for(Unit *u : allUnits()){
        for(Entity *e : staticEntities()){
            if(u->collidesWithItem(e)){
                //u->setTarget(e->pos()-QPointF(5,5));
                u->stopMoving();
                break;
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
    player.update();

    solveCollisions();

    viewport()->update();
}

void Warcraft::mousePressEvent(QMouseEvent *event){

    QPointF actualPos = mapToScene(mapFromGlobal(QCursor::pos()));
    if(event->button() == Qt::LeftButton){
        isPressedLeftButton = true;
        position->setX(actualPos.x());
        position->setY(actualPos.y());


        for(Unit *unit : player.getUnits()){
            if(unit->boundingRect().translated(unit->pos()).contains(actualPos)){
                player.selectUnit(unit);
            }
        }
        for(Worker *worker : player.getWorkers()){
            if(worker->boundingRect().translated(worker->pos()).contains(actualPos)){
                player.selectUnit(worker);
            }
        }

    } else if (event->button() == Qt::RightButton){
        int i = 0 ;
        for(Unit *unit : player.getSelectedUnits()){
            unit->cancel();
            unit->setTarget(actualPos+QPoint(i,i));
            unit->move();
            i +=40;
        }

    }
}

void Warcraft::mouseReleaseEvent(QMouseEvent *releaseEvent)
{
    if(releaseEvent->button() == Qt::LeftButton){

        isPressedLeftButton = false;

        QList<Unit *> selected;
        for(Unit *unit : player.getUnits()){
            if(rect->rect().contains(unit->boundingRect().translated(unit->pos()).center())){
                selected.append(unit);
            }
        }
        for(Worker *worker : player.getWorkers()){
            if(rect->rect().contains(worker->boundingRect().translated(worker->pos()).center())){
                selected.append(worker);
            }
        }
        player.selectUnits(selected);

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
}


QList<Entity *> Warcraft::staticEntities(){
    QList<Entity *> list;
    for(Building *b : player.getBuildings()){
        list.append(b);
    }
    for(Goldmine *g : *goldmines){
        list.append(g);
    }
    return list;
}

QList<Unit *> Warcraft::allUnits(){
    QList<Unit *> allUnits;
    allUnits.append(player.getUnits());
    allUnits.append(enemy.getUnits());
    for(Worker *w : player.getWorkers()){
        allUnits.append(w);
    }
    for(Worker *w : enemy.getWorkers()){
        allUnits.append(w);
    }
    return allUnits;

}

void Warcraft::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);
    QPainter painter(viewport());
    painter.setFont(QFont("sans-serif",10));
    painter.setPen(Qt::white);
    painter.drawText(QPointF(700, 20), QString("FOOD: "+QString::number(player.getFood())+"   GOLD: "+QString::number(player.getGold())+"   LUMBER: "+QString::number(player.getLumber())));

}

