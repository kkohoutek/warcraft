#ifndef BUILDHUMANFARM_HPP
#define BUILDHUMANFARM_HPP

#include "ResourceManager.hpp"
#include "Player.hpp"
#include <QGraphicsPixmapItem>

class BuildHumanFarm : public QGraphicsPixmapItem
{
public:
    BuildHumanFarm(QPointF pos, Player *player, ResourceManager *rm);

    QRectF boundingRect() const override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPixmap image;
    Player *player;
};

#endif // BUILDHUMANFARM_HPP
