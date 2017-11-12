#include "HumanTownHall.hpp"

HumanTownHall::HumanTownHall(QPointF pos, bool finishedOnSpawn, ResourceManager *rm, Player *player) : TrainingBuilding(pos, H_TOWNHALL, finishedOnSpawn, HUMAN, QList<int>() << 3 << 2, QList<int>() << 2 << 2, BUILD_TIME, HP, rm, player) {

}

QRectF HumanTownHall::boundingRect() const {
    return QRectF(0,0,96,96);
}
