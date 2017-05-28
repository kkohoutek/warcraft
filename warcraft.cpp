#include "warcraft.h"
#include "entity/entity.h"
#include "animation.h"

#include <QGraphicsScene>
#include <QMouseEvent>

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
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,1024);


    /* První se budou testovat budovy */
    // testing
    scene->addItem(new HumanFarm(QPointF(512,512), false));
    scene->addItem(new HumanBlacksmith(QPointF(450,502), false));
    scene->addItem(new HumanChurch(QPointF(450,555), false));
    scene->addItem(new HumanBarracks(QPointF(450,400), false));
    scene->addItem(new HumanStables(QPointF(410, 512), false));
    scene->addItem(new HumanTower(QPointF(410, 385), false));




    setScene(scene);
    startTimer(17);
    setTransform(QTransform().scale(2,2));
    setMouseTracking(true);






}

void Warcraft::timerEvent(QTimerEvent *event) {
    viewport()->update();
}

void Warcraft::keyPressEvent(QKeyEvent *event){

}

