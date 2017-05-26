#include "warcraft.h"
#include "entity/entity.h"
#include "animation.h"

#include <QGraphicsScene>
#include <QMouseEvent>

#include "entity/building/building.h"

Warcraft::Warcraft()
{

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,1024);


    // testing
    Building *farm = new Building(QPointF(512,512), Building::H_FARM);
    scene->addItem(farm);

    Building *bs = new Building(QPointF(470,512), Building::H_BLACKSMITH);
    scene->addItem(bs);

    this->setScene(scene);
    this->startTimer(17);
    this->setTransform(QTransform().scale(3,3));
    // testing


}

void Warcraft::timerEvent(QTimerEvent *event)
{
    this->viewport()->update();
}

