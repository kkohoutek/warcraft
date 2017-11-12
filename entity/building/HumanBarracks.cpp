#include "HumanBarracks.hpp"

HumanBarracks::HumanBarracks(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, Player *player) : TrainingBuilding(pos, H_BARRACKS, finishedOnSpawn, HUMAN, QList<int>() << 1 << 2, QList<int>() << 0 << 2, BUILD_TIME, HP, rm, player)
{
}

QRectF HumanBarracks::boundingRect() const {
    return QRectF(0,0,96,96);
}
