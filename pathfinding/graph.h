#ifndef GRAPH_H
#define GRAPH_H

#include "entity/entity.h"

#define NODES_DISTANCE 32
#define NODES_ARRAY_SIZE 1024/NODES_DISTANCE-1

struct Node {
    Node(const int x, const int y) { pos.setX(x); pos.setY(y); }
    bool                visited = false;
    QPointF             pos;
    Node                *neighbors[4] = {nullptr,nullptr,nullptr,nullptr};
    Node                *parent = nullptr;
};

class Graph
{
public:
    Graph();
    // Constructs a graph and updates it
    Graph(const QList<Entity *> &obstacles);
    ~Graph();

    Node *nodes[NODES_ARRAY_SIZE][NODES_ARRAY_SIZE];

    void update(const QList<Entity *> &obstacles);

    QList<QPointF> BFS_shortestPath(Node *start, Node *goal);
    QList<QPointF> BFS_shortestPath(QPointF a, QPointF b);

    // Return node closest to these coords
    Node *gimmeNode(QPointF pos);

    // Resets visited and parent property of nodes
    void resetNodes();
};

#endif // GRAPH_H
