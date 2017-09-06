#ifndef WORKER_H
#define WORKER_H

#include "unit.h"
#include "entity/goldmine.h"
#include "entity/trees.h"
#include "entity/building/building.h"
#include "resourcemanager.h"

class Worker : public Unit
{
public:
    Worker(QPointF pos, Race race, int &playerGold, int &playerLumber, ResourceManager *rm);
    ~Worker();

    QRectF boundingRect() const override;

    void gatherGold(Goldmine *source, Building *destination);
    void gatherLumber(Trees *source, Building *destination);
    void stopWorking();
    void goBuild(Building *building);
    void update() override;
    void cancel() override;

    bool isGatheringGold() const;
    bool isGatheringLumber() const;

    Building *getCurrentBuilding() const;

protected:
    static const int GOLD_PER_TRIP = 100;

    Goldmine *currentGoldmine = nullptr;
    Trees    *currentTrees = nullptr;
    Building *lumberDestination = nullptr;
    Building *goldDestination = nullptr;
    Building *currentBuilding = nullptr;

    void updateAnimation() override;

private:
    QList<Animation *> miningAnims;
    QList<Animation *> goldCarryAnims;
    QList<Animation *> woodCarryAnims;

    int *playerGold;    // pointer na hráčovo zlato
    int *playerLumber;  // pointer na hráčovo dřevo



};

#endif // WORKER_H
