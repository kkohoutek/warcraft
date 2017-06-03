#include "warcraft.h"
#include "entity/entity.h"
#include "animation.h"

#include <QGraphicsScene>
#include <QMouseEvent>
#include <QScrollBar>

#include "entity/building/humanfarm.h"
#include "entity/building/humanblacksmith.h"
#include "entity/building/humanchurch.h"
#include "entity/building/humanbarracks.h"
#include "entity/building/humanstables.h"
#include "entity/building/humantownhall.h"
#include "entity/building/humanlumbermill.h"
#include "entity/building/humantower.h"

Warcraft::Warcraft()
{

    this->verticalScrollBar()->hide();
    this->horizontalScrollBar()->hide();

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,1024);


    setScene(scene);
    startTimer(17);
    setTransform(QTransform().scale(2,2));
    setMouseTracking(true);


    loadBackground();
    loadBuildings();





}

void Warcraft::loadBackground()
{
    QRect rect(0, 0, 32, 32);
    QImage original(":graphics/WORLD");
    QImage cropped = original.copy(rect);
    QBrush brush(cropped);
    brush.setStyle(Qt::TexturePattern);
    scene()->setBackgroundBrush(brush);

}

void Warcraft::loadBuildings()
{
    // testing
    scene()->addItem(new HumanFarm(QPointF(512,512), false));
    scene()->addItem(new HumanBlacksmith(QPointF(460,502), false));
    scene()->addItem(new HumanChurch(QPointF(450,572), false));
    scene()->addItem(new HumanBarracks(QPointF(450,400), false));
    scene()->addItem(new HumanStables(QPointF(410, 512), false));
    scene()->addItem(new HumanTower(QPointF(390, 385), false));
    scene()->addItem(new HumanTownHall(QPointF(300, 500), false));

}

void Warcraft::timerEvent(QTimerEvent *event) {
    QPoint p = mapFromGlobal(QCursor::pos());
    if(p.x() >= this->viewport()->width() - 20){
        //this->viewport()->scroll(2,0);
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()+20);
    }
    else if(p.x() <= 20){
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()-20);
    }

    if(p.y() >= this->viewport()->height() - 20){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()+20);
    }

    else if(p.y() <= 20){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()-20);
    }


    viewport()->update();
}

void Warcraft::mouseMoveEvent(QMouseEvent *event){
    if(event->x() >= this->viewport()->width() - 8){
        //this->viewport()->scroll(2,0);
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()+8);
    }
    else if(event->x() <= 8){
        this->horizontalScrollBar()->setValue(horizontalScrollBar()->value()-8);
    }

    if(event->y() >= this->viewport()->height() - 8){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()+8);
    }

    else if(event->y() <= 8){
        this->verticalScrollBar()->setValue(verticalScrollBar()->value()+8);
    }


}

void Warcraft::keyPressEvent(QKeyEvent *event){

}

