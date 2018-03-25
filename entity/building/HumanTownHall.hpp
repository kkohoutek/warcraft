#ifndef HUMANTOWNHALL_HPP
#define HUMANTOWNHALL_HPP

#include "TrainingBuilding.hpp"

class HumanTownHall : public TrainingBuilding
{
public:
    static const int COST_GOLD = 800;
    static const int COST_LUMBER = 0;
    static const int HP = 2500;
    static const int BUILD_TIME = 40000;

    HumanTownHall(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, Player *player);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

};

#endif // HUMANTOWNHALL_HPP
