#ifndef HUMANBARRACKS_HPP
#define HUMANBARRACKS_HPP

#include "TrainingBuilding.hpp"

class HumanBarracks : public TrainingBuilding
{
public:
    static const int COST_GOLD = 1100;
    static const int COST_LUMBER = 0;
    static const int HP = 800;
    static const int BUILD_TIME = 60000;

    HumanBarracks(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, Player *player);
    QRectF boundingRect() const override;
};

#endif // HUMANBARRACKS_HPP
