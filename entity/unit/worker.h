#ifndef WORKER_H
#define WORKER_H

#include "unit.h"
#include "entity/goldmine.h"
#include "entity/tree.h"
#include "entity/building/building.h"

class Worker : public Unit
{
public:
    Worker(QPointF pos);

    void gatherGold(Goldmine *source, Building *destination);
    void gatherLumber(Tree *source, Building *destination);
    void stopGathering();
    bool isGatheringGold();
    bool isGatheringLumber();

protected:
    Goldmine *currentGoldmine = NULL;
    Tree    *currentTree = NULL;
    Building *lumberDestination = NULL;
    Building *goldDestination = NULL;

};

#endif // WORKER_H
