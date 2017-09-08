#ifndef GRAPH_H
#define GRAPH_H

#include "entity/entity.h"

#define NODES_DISTANCE 32
#define NODES_ARRAY_SIZE 1024/NODES_DISTANCE-1 // square array

struct Node {
    Node() { visited = false; neighbors.reserve(4) ;}
    Node(const int x, const int y) : Node() { pos.setX(x); pos.setY(y); }
    bool                visited;
    QPointF             pos;
    QVector<Node *>     neighbors;
    Node                *parent;   // ze které node jsme přišli
};

class Graph
{
public:
    Graph();
    Graph(const QList<Entity *> &obstacles);
    ~Graph();

    Node *nodes[NODES_ARRAY_SIZE][NODES_ARRAY_SIZE];

    // return node closest to these coords
    Node *gimmeNode(QPointF pos);

    void resetNodes();
};

#endif // GRAPH_H
