#include "garbagecollector.h"
#include <QMutableListIterator>
#include <QGraphicsScene>
#include <QDebug>
GarbageCollector::GarbageCollector(Player *monitoredPlayer, const int interval) : QObject(nullptr) {
    this->monitoredPlayer = monitoredPlayer;

    updateTimer.setInterval(interval);
    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer.start();
}

void GarbageCollector::update(){
    QMutableListIterator<Unit *> a(monitoredPlayer->getUnits());
    while(a.hasNext()){
        Unit *unit = a.next();
        if(!unit->isAlive()){
            qDebug() << "GC: Deleting unit (type " + QString::number(unit->getType()) + ") at " + QString::number(unit->pos().x());
            a.remove();
            unit->scene()->removeItem(unit);
            delete unit;
        }
    }
    QMutableListIterator<Building *> c(monitoredPlayer->getBuildings());
    while(c.hasNext()){
        Building *building = c.next();
        if(!building->isAlive() && building->isBuildingFinished()){
            qDebug() << "GC: Deleting building (type " + QString::number(building->getType()) + ") at " + QString::number(building->pos().x());
            c.remove();
            building->scene()->removeItem(building);
            delete building;
        }
    }


}


