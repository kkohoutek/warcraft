#include "warcraft.h"
#include "entity/entity.h"
#include "animation.h"

#include <QGraphicsScene>
#include <QMouseEvent>
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


Worker *worker;

Warcraft::Warcraft()
{

    this->verticalScrollBar()->hide();
    this->horizontalScrollBar()->hide();

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,2048,2048);


    setScene(scene);
    startTimer(17);
    //setTransform(QTransform().scale(2,2));
    setMouseTracking(true);


    player = new Player(HUMAN);
    enemy = new Player(ORC);

    player->addGold(10000);
    player->addLumber(10000);
    player->addFood(10000);

    loadBackground();
    worker = new Worker(QPointF(500,1024) , HUMAN);
    scene->addItem(worker);
    newBuilding(new HumanFarm(QPointF(1023,1023),false),worker,player,HumanFarm::COST_GOLD,HumanFarm::COST_LUMBER);
    loadBuildings();

}

Warcraft::~Warcraft()
{
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
    if(p.x() >= this->viewport()->width() - 40 && p.x() <= this->window()->width() ){
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()+20);

    }
    else if(p.x() <= 40 && p.x() >= 0 ){
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()-20);

    }

    if(p.y() >= this->viewport()->height() - 40 && p.y() <= this->window()->height()){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()+20);

    }

    else if(p.y() <= 40 && p.y() >= 0){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()-20);

    }

    worker->update();

    viewport()->update();
}

void Warcraft::mousePressEvent(QMouseEvent *event){
    qDebug() << event->pos();
}

void Warcraft::newBuilding(Building *building, Worker *worker, Player *player, int costGold, int costLumber) {

    if(player->getGold() > costGold && player->getLumber() > costLumber){
        player->addGold(-costGold);
        player->addLumber(-costLumber);
        worker->goBuild(building);
    }

}





