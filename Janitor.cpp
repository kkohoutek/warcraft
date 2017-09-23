#include "Janitor.hpp"
#include <QMutableListIterator>

Janitor::Janitor(Warcraft *game) : QObject(game) {
    this->game = game;
    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer.setInterval(3000);
    updateTimer.start();
}

void Janitor::update() {

    while(!delQueue.isEmpty()){
        Entity **e = delQueue.dequeue();
        (*e)->scene()->removeItem((*e));
        delete *e;
    }

    QMutableListIterator<Unit *> i(game->player->getUnits());
    while(i.hasNext()){
        auto *&e = i.next();
        if(!e->isAlive()){
            i.remove();
            delete e;
            e = nullptr;
        }
    }
    QMutableListIterator<Unit *> j(game->enemy->getUnits());
    while(j.hasNext()){
        auto *&e = j.next();
        if(!e->isAlive()){
            j.remove();
            delete e;
            e = nullptr;
        }
    }


    QMutableListIterator<Building *> k(game->player->getBuildings());
    while(k.hasNext()){
        auto *&e = k.next();
        if(!e->isAlive()){
            k.remove();
            delete e;
            e = nullptr;

        }
    }
    QMutableListIterator<Building *> l(game->enemy->getBuildings());
    while(l.hasNext()){
        auto *&e = l.next();
        if(e->isAlive()){
            l.remove();
            delete e;
            e = nullptr;
        }
    }

    /*
    QMutableListIterator<Goldmine *> m(game->goldmines);
    while(m.hasNext()){
        auto **e = m.next();
        if(!(*e)->isAlive()){
            delQueue.enqueue((*e));
            m.remove();
        }
    }*/
}
