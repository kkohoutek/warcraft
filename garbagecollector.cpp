#include "garbagecollector.h"
#include <QMutableListIterator>
#include <QGraphicsScene>

GarbageCollector::GarbageCollector(Player *monitoredPlayer, const int interval) : QObject(NULL) {
    this->monitoredPlayer = monitoredPlayer;

    updateTimer = new QTimer();
    updateTimer->setInterval(interval);
    connect(updateTimer, &QTimer::timeout, this, &update);
    updateTimer->start();
}

GarbageCollector::~GarbageCollector(){
    delete updateTimer;
}

void GarbageCollector::update(){

    QMutableListIterator<Unit *> a(monitoredPlayer->getUnits());
    while(a.hasNext()){
        Unit *unit = a.next();
        if(unit->getHP() == 0){
            a.remove();
            unit->scene()->removeItem(unit);
            delete unit;
        }
    }

    QMutableListIterator<Worker *> b(monitoredPlayer->getWorkers());
    while(b.hasNext()){
        Worker *worker = b.next();
        if(worker->getHP() == 0){
            b.remove();
            worker->scene()->removeItem(worker);
            delete worker;
        }
    }

    QMutableListIterator<Building *> c(monitoredPlayer->getBuildings());
    while(c.hasNext()){
        Building *building = c.next();
        if(building->getHP() == 0){
            c.remove();
            building->scene()->removeItem(building);
            delete building;
        }
    }


}


