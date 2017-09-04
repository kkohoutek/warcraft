#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"

class Graph
{
public:
    Graph();
    ~Graph();

    // maps must be 2048x2048
    Node *nodes[64][64];

    // return node closest to these coords
    Node *gimmeNode(QPointF pos);


};

#endif // GRAPH_H
