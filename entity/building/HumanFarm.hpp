#ifndef HUMANFARM_HPP
#define HUMANFARM_HPP

#include "Building.hpp"

class HumanFarm : public Building
{
public:
    static const int COST_GOLD = 800;
    static const int COST_LUMBER = 0;
    static const int HP = 400;
    static const int BUILD_TIME = 40000;

    HumanFarm(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, int *playerFood);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

    void update() override;

private:
    int *playerFood; // pointer na hráčovo jídlo
    bool foodIncreased = false;
};

#endif // HUMANFARM_HPP
