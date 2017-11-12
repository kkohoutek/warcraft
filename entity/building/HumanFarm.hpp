#ifndef HUMANFARM_HPP
#define HUMANFARM_HPP

#include "Building.hpp"



class HumanFarm : public Building
{
public:
    static const int COST_GOLD = 500;
    static const int COST_LUMBER = 300;
    static const int HP = 800;
    static const int BUILD_TIME = 5000;

    HumanFarm(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, int *playerFood);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

    void update() override;

private:
    int *playerFood; // pointer na hráčovo jídlo
    bool foodIncreased = false;
};

#endif // HUMANFARM_HPP
