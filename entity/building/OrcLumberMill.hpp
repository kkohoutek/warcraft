#ifndef ORCLUMBERMILL_HPP
#define ORCLUMBERMILL_HPP
#include "Building.hpp"


class OrcLumberMill : public Building
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 0;
    static const int HP = 600;
    static const int BUILD_TIME = (1500*1000)/100;

    OrcLumberMill(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
};

#endif // ORCLUMBERMILL_HPP
