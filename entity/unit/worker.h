#ifndef WORKER_H
#define WORKER_H

#include "unit.h"
#include "entity/goldmine.h"
#include "entity/trees.h"
#include "entity/building/building.h"

class Worker : public Unit
{
public:
    Worker(QPointF pos, Race race, int &playerGold, int &playerLumber);
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
    static const int GOLD_PER_TRIP = 10;

    Goldmine *currentGoldmine = NULL;
    Trees     *currentTrees = NULL;
    Building *lumberDestination = NULL;
    Building *goldDestination = NULL;
    Building *currentBuilding = NULL;

    void updateAnimation() override;

private:
    QList<Animation *> *miningAnims;
    QList<Animation *> *goldCarryAnims;
    QList<Animation *> *woodCarryAnims;

    int *playerGold;    // pointer na hráčovo zlato
    int *playerLumber;  // pointer na hráčovo dřevo

};

#endif // WORKER_H
