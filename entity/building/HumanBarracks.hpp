#ifndef HUMANBARRACKS_HPP
#define HUMANBARRACKS_HPP

#include "TrainingBuilding.hpp"

class HumanBarracks : public TrainingBuilding
{
public:
    static const int COST_GOLD = 400;
    static const int COST_LUMBER = 400;
    static const int HP = 2500;
    static const int BUILD_TIME = 5000;

    HumanBarracks(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, Player *player);
    QRectF boundingRect() const override;
};

#endif // HUMANBARRACKS_HPP
