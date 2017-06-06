#ifndef TREE_H
#define TREE_H

#include "entity.h"



class Tree : public Entity
{
public:
    Tree(QPointF pos);

    // QGraphicsItem interface
    QRectF boundingRect() const;

    // Entity interface
    void update();


};

#endif // TREE_H
