#ifndef GRAPH_H
#define GRAPH_H

#define NODES_DISTANCE 32
#define NODES_ARRAY_SIZE 2048/NODES_DISTANCE // square array

#include "node.h"
#include "entity/entity.h"

class Graph
{
public:
    Graph();
    Graph(QList<Entity *> obstacles);
    ~Graph();

    // 2048/32 = 64
    Node *nodes[NODES_ARRAY_SIZE][NODES_ARRAY_SIZE];

    // return node closest to these coords
    Node *gimmeNode(QPointF pos);

    void resetNodes();
};

#endif // GRAPH_H
