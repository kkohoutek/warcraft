#ifndef HUMANCHURCH_HPP
#define HUMANCHURCH_HPP

#include "Building.hpp"
class HumanChurch : public Building
{
public:
    static const int COST_GOLD = 800;
    static const int COST_LUMBER = 500;
    static const int HP = 700;
    static const int BUILD_TIME = (2000*1000)/100;
    HumanChurch(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    QRectF boundingRect() const override;
};

#endif // HUMANCHURCH_HPP
