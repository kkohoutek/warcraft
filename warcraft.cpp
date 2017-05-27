#include "warcraft.h"
#include "entity/entity.h"
#include "animation.h"

#include <QGraphicsScene>
#include <QMouseEvent>

#include "entity/building/humanfarm.h"
#include "entity/building/humanblacksmith.h"

Warcraft::Warcraft()
{

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,1024);


    /* První se budou testovat budovy */
    // testing
    HumanFarm *farm = new HumanFarm(QPointF(512,512), false);
    scene->addItem(farm);

    HumanBlacksmith *bs = new HumanBlacksmith(QPointF(450,502), false);
    scene->addItem(bs);

    this->setScene(scene);
    this->startTimer(17);
    this->setTransform(QTransform().scale(3,3));

    // testing


}

void Warcraft::timerEvent(QTimerEvent *event) {
    this->viewport()->update();
}

void Warcraft::keyPressEvent(QKeyEvent *event){

}

