#include "garbagecollector.h"
#include <QMutableListIterator>
#include <QGraphicsScene>

GarbageCollector::GarbageCollector(Player *monitoredPlayer, const int interval) : QObject(nullptr) {
    this->monitoredPlayer = monitoredPlayer;

    updateTimer.setInterval(interval);
    connect(&updateTimer, &QTimer::timeout, this, &update);
    updateTimer.start();
}

void GarbageCollector::update(){
    QMutableListIterator<Unit *> a(monitoredPlayer->getUnits());
    while(a.hasNext()){
        Unit *unit = a.next();
        if(!unit->isAlive()){
            a.remove();
            unit->scene()->removeItem(unit);
            delete unit;
        }
    }
    QMutableListIterator<Building *> c(monitoredPlayer->getBuildings());
    while(c.hasNext()){
        Building *building = c.next();
        if(!building->isAlive()){
            c.remove();
            building->scene()->removeItem(building);
            delete building;
        }
    }


}


