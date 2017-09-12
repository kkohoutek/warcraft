#ifndef BUILDHUMANFARM_H
#define BUILDHUMANFARM_H

#include"resourcemanager.h"
#include "player.h"
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

#endif // BUILDHUMANFARM_H
