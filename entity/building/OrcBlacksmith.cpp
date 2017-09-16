#include "OrcBlacksmith.hpp"

OrcBlacksmith::OrcBlacksmith(QPointF pos, bool finishedOnSpawn, ResourceManager *rm) :
    Building(pos, O_BLACKSMITH, finishedOnSpawn,ORC, QList<int>() << 3 << 0, QList<int>() << 2 << 0, BUILD_TIME, HP, rm)
{

}

QRectF OrcBlacksmith::boundingRect() const
{
    return QRectF(4,4,82,82);
}

