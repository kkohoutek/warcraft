#ifndef WORKER_H
#define WORKER_H

#include "unit.h"
#include "entity/goldmine.h"
#include "entity/trees.h"
#include "entity/building/building.h"
#include "resourcemanager.h"
#include "pathfinding.h"

#define GOLD_PER_TRIP 10

struct BuildCommand {
    Building *what;
    BuildCommand(Building *what) { this->what = what; }
};

struct MineCommand {
    Goldmine *source;
    Building *dest;
    QList<QPointF> path;
    MineCommand(Goldmine *source, Building *dest) { this->source = source; this->dest = dest; }
};

struct HarvestCommand {
    Trees *source;
    Building *dest;
    QList<QPointF> path;
    HarvestCommand(Trees *source, Building *dest) { this->source = source; this->dest = dest; }
};

class Worker : public Unit
{
public:
    Worker(QPointF pos, UnitType type, int *playerGold, int *playerLumber, Graph *graph, ResourceManager *rm);
    ~Worker();

    void update() override;
    void cancel() override;
    QRectF boundingRect() const override;

    void mine(Goldmine *source, Building *dest);
    void harvest(Trees *source, Building *dest);
    void build(Building *building);

protected:
    HarvestCommand  *harvestCommand     = nullptr;
    BuildCommand    *buildCommand       = nullptr;
    MineCommand     *mineCommand        = nullptr;

    void updateAnimation() override;

private:
    QList<Animation *> miningAnims;
    QList<Animation *> goldCarryAnims;
    QList<Animation *> woodCarryAnims;

    int *playerGold;    // Pointer na hráčovo zlato
    int *playerLumber;  // Pointer na hráčovo dřevo
    Graph *graph;       // Pointer na pathfinding graph

};



#endif // WORKER_H
