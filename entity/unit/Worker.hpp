#ifndef WORKER_HPP
#define WORKER_HPP

#include "Unit.hpp"
#include "entity/Goldmine.hpp"
#include "entity/Trees.hpp"
#include "entity/building/Building.hpp"
#include "ResourceManager.hpp"



class Worker : public Unit
{
public:
    Worker(QPointF pos, Unit::Type type, int *playerGold, int *playerLumber, Graph *graph, ResourceManager *rm);
    ~Worker();

    void    update() override;
    void    cancel() override;
    bool    canSelect() const override;
    QRectF  boundingRect() const override;

    void    mine(Goldmine *source, Building *dest);
    void    harvest(Trees *source, Building *dest);
    void    build(Building *building);

protected:
    struct BuildCommand {
        Building *what;
        BuildCommand(Building *what) { this->what = what; }
    };

    struct MineCommand {
        Goldmine *source;
        Building *dest;
        //QList<QPointF> path;
        MineCommand(Goldmine *source, Building *dest) { this->source = source; this->dest = dest; }
    };

    struct HarvestCommand {
        Trees *source;
        Building *dest;
        QList<QPointF> path;
        HarvestCommand(Trees *source, Building *dest) { this->source = source; this->dest = dest; }
    };

    HarvestCommand  *harvestCommand     = nullptr;
    BuildCommand    *buildCommand       = nullptr;
    MineCommand     *mineCommand        = nullptr;

    void updateAnimation() override;

private:
    QList<Animation *> miningAnims;
    QList<Animation *> goldCarryAnims;
    QList<Animation *> woodCarryAnims;

    int     *playerGold;    // Pointer na hráčovo zlato
    int     *playerLumber;  // Pointer na hráčovo dřevo
    Graph   *graph;         // Pointer na pathfinding graph

};



#endif // WORKER_HPP
