#ifndef HUMANTOWER_HPP
#define HUMANTOWER_HPP

#include "Building.hpp"
class HumanTower : public Building
{
public:
    static const int COST_GOLD = 1400;
    static const int COST_LUMBER = 0;
    static const int HP = 900;
    static const int BUILD_TIME = (2000*1000)/100;

    HumanTower(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);
    QRectF boundingRect() const override;
};

#endif // HUMANTOWER_HPP
