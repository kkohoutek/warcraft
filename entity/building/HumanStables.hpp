#ifndef HUMANSTABLES_HPP
#define HUMANSTABLES_HPP

#include "Building.hpp"
class HumanStables : public Building
{
public:
    static const int COST_GOLD = 1000;
    static const int COST_LUMBER = 0;
    static const int HP = 500;
    static const int BUILD_TIME = (1500*1000)/100;

    HumanStables(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);
    QRectF boundingRect() const override;

};

#endif // HUMANSTABLES_HPP
