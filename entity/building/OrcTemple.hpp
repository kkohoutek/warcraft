#ifndef ORCTEMPLE_HPP
#define ORCTEMPLE_HPP
#include "Building.hpp"


class OrcTemple : public Building
{
public:
    static const int COST_GOLD = 800;
    static const int COST_LUMBER = 500;
    static const int HP = 700;
    static const int BUILD_TIME = (2000*1000)/100;
    OrcTemple(QPointF pos, bool finishedOnSpawn, ResourceManager *rm);

    // QGraphicsItem interface

    QRectF boundingRect() const override;
};

#endif // ORCTEMPLE_HPP
