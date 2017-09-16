#ifndef HUMANLUMBERMILL_HPP
#define HUMANLUMBERMILL_HPP

#include "Building.hpp"
class HumanLumberMill : public Building
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 500;
    static const int HP = 600;
    static const int BUILD_TIME = (1500*1000)/100;
    HumanLumberMill(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    QRectF boundingRect() const override;

};

#endif // HUMANLUMBERMILL_HPP
