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
#include "entity/unit/peasant.h"

Footman *f;
Peasant *w;

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

    f = new Footman(QPointF(200,300));
    scene->addItem(f);

    w = new Peasant(QPointF(200,250));
    scene->addItem(w);



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
    scene()->addItem(new HumanFarm(QPointF(160,512), false));
    scene()->addItem(new HumanBlacksmith(QPointF(410,502), false));
    scene()->addItem(new HumanChurch(QPointF(500,572), false));
    scene()->addItem(new HumanBarracks(QPointF(600,400), false));
    scene()->addItem(new HumanStables(QPointF(410, 330), false));
    scene()->addItem(new HumanTower(QPointF(290, 390), false));
    scene()->addItem(new HumanTownHall(QPointF(300, 500), false));

}

void Warcraft::timerEvent(QTimerEvent *event) {
    QPoint p = mapFromGlobal(QCursor::pos());
    if(p.x() >= this->viewport()->width() - 20){
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

    //f->update();
    w->update();

    viewport()->update();
}

void Warcraft::mousePressEvent(QMouseEvent *event){
    qDebug() << event->pos();;
}


void Warcraft::keyPressEvent(QKeyEvent *event){

}

