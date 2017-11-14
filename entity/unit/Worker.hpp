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
        //QList<QPointF> path;
        HarvestCommand(Trees *source, Building *dest) { this->source = source; this->dest = dest; }
    };

    HarvestCommand  *harvestCommand     = nullptr;
    BuildCommand    *buildCommand       = nullptr;
    MineCommand     *mineCommand        = nullptr;

    void updateAnimation() override;
    Building *findClosestGoldDestination() const;

private:
    QList<Animation *> miningAnims;
    QList<Animation *> goldCarryAnims;
    QList<Animation *> woodCarryAnims;

    Player *player;

};



#endif // WORKER_HPP
