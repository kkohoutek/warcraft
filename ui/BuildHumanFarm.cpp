#include "BuildHumanFarm.hpp"

BuildHumanFarm::BuildHumanFarm(QPointF pos, Player *player, ResourceManager *rm)  {
    this->player = player;
    setPos(pos);
    image = rm->getSprite("BUILDINGS_H")->copy();
    setPixmap(rm->getSprite("ICONS")->copy(QRect(QPoint(0,19), QPoint(27,2*19))));

}

QRectF BuildHumanFarm::boundingRect() const {
    return QRectF(0,0,27,19);
}

void BuildHumanFarm::mousePressEvent(QGraphicsSceneMouseEvent *event) {

}
