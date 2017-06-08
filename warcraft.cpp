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

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,2048,2048);

    rect = new QGraphicsRectItem();
    position = new QPoint();

    setScene(scene);
    startTimer(17);
    //setTransform(QTransform().scale(2,2));
    setMouseTracking(true);
    loadBackground();


    player = new Player(HUMAN);
    enemy = new Player(ORC);

    player->addGold(10000);
    player->addLumber(10000);
    player->addFood(10000);

    Worker *w =new Worker(QPointF(500,1024), HUMAN);
    Footman *f = new Footman(QPointF(555, 1066));
    //player->getUnits().append(f);
    player->getWorkers().append(w);


    player->newBuilding(new HumanFarm(QPointF(1080,1555),false),w,HumanFarm::COST_GOLD,HumanFarm::COST_LUMBER);

    scene->addItem(w);
    scene->addItem(f);
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

void Warcraft::loadBuildings()
{
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
        for(Unit *unit : *player->getUnits()){
            if(rect->rect().contains(unit->boundingRect().translated(unit->pos()).center())){
                selected.append(unit);
            }
        }
        for(Worker *worker : *player->getWorkers()){
            if(rect->rect().contains(worker->boundingRect().translated(worker->pos()).center())){
                selected.append(worker);
            }
        }
        if(!selected.empty()) player->selectUnits(selected);*/

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

