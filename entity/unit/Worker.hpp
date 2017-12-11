#ifndef WORKER_HPP
#define WORKER_HPP

#include "entity/Goldmine.hpp"
#include "entity/Trees.hpp"
#include "Player.hpp"

class Worker : public Unit
{
public:
    static const int COST_GOLD = 400;
    static const int COST_LUMBER = 0;

    Worker(QPointF pos, Unit::Type type, Player *player, ResourceManager *rm);
    ~Worker();

    void    attack(Entity *victim) override;
    void    update() override;
    void    cancel() override;
    bool    isSelectable() const override;
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
        PATH path;  // Cesta od dolu k budově
        PATH path2; // Cesta od budovy k dolu
        MineCommand(Goldmine *source, Building *dest, Graph *graph) {
            this->source = source;
            this->dest = dest;
            path = graph->shortestPath(source->center(), dest->center());
            path2 = graph->shortestPath(dest->center(), source->center());
        }
    };

    struct HarvestCommand {
        Trees *source;
        Building *dest;
        HarvestCommand(Trees *source, Building *dest) { this->source = source; this->dest = dest; }
    };

    HarvestCommand  *harvestCommand     = nullptr;
    BuildCommand    *buildCommand       = nullptr;
    MineCommand     *mineCommand        = nullptr;

    Building *findClosestGoldDestination() const;

private:
    QList<Animation *> miningAnims;
    QList<Animation *> goldCarryAnims;
    QList<Animation *> woodCarryAnims;

    Player *player;
};



#endif // WORKER_HPP
