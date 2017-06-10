#include "warcraft.h"
#include "entity/entity.h"
#include "animation.h"

#include <QGraphicsScene>
#include <QScrollBar>
#include <QDebug>

#include "entity/building/humanfarm.h"
#include "entity/building/humanblacksmith.h"
#include "entity/building/humanchurch.h"
#include "entity/building/humanbarracks.h"
#include "entity/building/humanstables.h"
#include "entity/building/humantownhall.h"
#include "entity/building/humanlumbermill.h"
#include "entity/building/humantower.h"
#include "entity/unit/footman.h"

Warcraft::Warcraft()
{
    this->verticalScrollBar()->hide();
    this->horizontalScrollBar()->hide();
    setMouseTracking(true);

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,2048,2048);

    rect = new QGraphicsRectItem();
    position = new QPoint();

    setScene(scene);

    player = new Player(HUMAN);
    enemy = new Player(ORC);

    player->addGold(10000);
    player->addLumber(10000);
    player->addFood(10000);


    loadBackground();
    loadWorld();
    loadUnits();
    loadBuildings();

    startTimer(17);
}

Warcraft::~Warcraft() {
    delete enemy;
    delete player;
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

}

void Warcraft::loadUnits(){
    for(int i = 0; i < 4; i++){
        Worker *w = new Worker(QPointF(128+i*28,128), player->getRace());
        player->getWorkers().append(w);
        scene()->addItem(w);
    }

    Footman *f = new Footman(QPointF(112,138));
    scene()->addItem(f);
    player->getUnits().append(f);
}

void Warcraft::loadWorld() {
    scene()->addItem(new Goldmine(QPointF(64,64)));
    scene()->addItem(new Goldmine(QPointF(2048-128, 2048-128)));


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

    player->update();

    viewport()->update();
}

void Warcraft::mousePressEvent(QMouseEvent *event){
    QPointF actualPos = mapToScene(mapFromGlobal(QCursor::pos()));
    if(event->button() == Qt::LeftButton){
        isPressedLeftButton = true;
        position->setX(actualPos.x());
        position->setY(actualPos.y());


        for(Unit *unit : player->getUnits()){
            if(unit->boundingRect().translated(unit->pos()).contains(actualPos)){
                player->selectUnit(unit);
            }
        }
        for(Worker *worker : player->getWorkers()){
            if(worker->boundingRect().translated(worker->pos()).contains(actualPos)){
                player->selectUnit(worker);
            }
        }

    } else if (event->button() == Qt::RightButton){
        for(Unit *unit : player->getSelectedUnits()){
            unit->cancel();
            unit->setTarget(actualPos);
            unit->move();
        }

    }
}

void Warcraft::mouseReleaseEvent(QMouseEvent *releaseEvent)
{
    if(releaseEvent->button() == Qt::LeftButton){

        isPressedLeftButton = false;

    /*
        QList<Unit *> selected;
        for(Unit *unit : player->getUnits()){
            if(rect->rect().contains(unit->boundingRect().translated(unit->pos()).center())){
                selected.append(unit);
            }
        }
        for(Worker *worker : player->getWorkers()){
            if(rect->rect().contains(worker->boundingRect().translated(worker->pos()).center())){
                selected.append(worker);
            }
        }
        player->selectUnits(selected);*/

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

