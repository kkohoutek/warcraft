#ifndef GRAPH_H
#define GRAPH_H

#define NODES_DISTANCE 32
#define NODES_ARRAY_SIZE 1024/NODES_DISTANCE-1 // square array


#include "node.h"
#include "entity/entity.h"

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
