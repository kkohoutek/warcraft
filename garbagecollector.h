#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

#include <QObject>
#include "player.h"

/*
Garbage collector, který monitoruje hráčovy entity
a maže ty, které již nejsou potřeba.
*/

class GarbageCollector : public QObject
{
    Q_OBJECT
public:
    GarbageCollector(Player *monitoredPlayer, const int interval);

private:
    QTimer updateTimer;
    Player *monitoredPlayer;

public slots:
    void update();
};

#endif // GARBAGECOLLECTOR_H
