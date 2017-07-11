#ifndef ORCTEMPLE_H
#define ORCTEMPLE_H
#include "building.h"


class OrcTemple : public Building
{
public:
    static const int COST_GOLD = 800;
    static const int COST_LUMBER = 500;
    static const int HP = 700;
    static const int BUILD_TIME = (2000*1000)/TIME_DIVISOR;

    OrcTemple(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
    void update() override;
};

#endif // ORCTEMPLE_H
