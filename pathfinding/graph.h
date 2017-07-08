#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"


class Graph
{
public:
    Graph();
    ~Graph();

    void                addNode(qreal x, qreal y);
    Node                *getNodeByPos(qreal x, qreal y);
    Node                *getClosestNode(qreal x, qreal y);
    QList<Node *>       &getNodes();

protected:
    QList<Node *>       nodes;


};

#endif // GRAPH_H
