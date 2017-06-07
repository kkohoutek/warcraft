#ifndef WORKER_H
#define WORKER_H

#include "unit.h"
#include "entity/goldmine.h"
#include "entity/tree.h"
#include "entity/building/building.h"

class Worker : public Unit
{
public:
    Worker(QPointF pos, Race race);
    QRectF boundingRect() const override;

    void gatherGold(Goldmine *source, Building *destination);
    void gatherLumber(Tree *source, Building *destination);
    void stopGathering();
    void goBuild(Building *building);
    void update() override;

    bool isGatheringGold();
    bool isGatheringLumber();
    bool isBuilding();

protected:
    Goldmine *currentGoldmine = NULL;
    Tree     *currentTree = NULL;
    Building *lumberDestination = NULL;
    Building *goldDestination = NULL;
    Building *currentBuilding = NULL;

private:
    QList<Animation *> *miningAnims;

};

#endif // WORKER_H
