#ifndef ORCLUMBERMILL_H
#define ORCLUMBERMILL_H
#include "building.h"


class OrcLumberMill : public Building
{
public:
    static const int COST_GOLD = 600;
    static const int COST_LUMBER = 500;
    static const int HP = 600;
    static const int BUILD_TIME = (1500*1000)/TIME_DIVISOR;

    OrcLumberMill(QPointF pos, bool finishedOnSpawn);

    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void update() override;
};

#endif // ORCLUMBERMILL_H
