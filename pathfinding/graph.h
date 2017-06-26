#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"


class Graph
{
public:
    Graph();
    ~Graph();

    void addNode(Node *node);
    Node *getNodeByPos(int x, int y);
    QList<Node *> getNodes();

protected:
    QList<Node *> *nodes;


};

#endif // GRAPH_H
