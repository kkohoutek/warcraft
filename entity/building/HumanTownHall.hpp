#ifndef HUMANTOWNHALL_HPP
#define HUMANTOWNHALL_HPP

#include "TrainingBuilding.hpp"

class HumanTownHall : public TrainingBuilding
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 500;
    static const int HP = 800;
    static const int BUILD_TIME = (1500*1000)/100;

    HumanTownHall(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;

};

#endif // HUMANTOWNHALL_HPP
