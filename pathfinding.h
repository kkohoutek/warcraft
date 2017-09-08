#ifndef GRAPH_H
#define GRAPH_H

#include "entity/entity.h"

#define NODES_DISTANCE 32
#define NODES_ARRAY_SIZE 2048/NODES_DISTANCE-2

struct Node {
    Node() { for(Node *n : neighbors) { n = nullptr; } }
    Node(const int x, const int y) : Node() { pos.setX(x); pos.setY(y); }
    bool                visited = false;
    QPointF             pos;
    Node                *neighbors[8];
    Node                *parent = nullptr;
};

class Graph
{
public:
    Graph();
    // Sestrojí graf a zavolá update
    Graph(const QList<Entity *> &obstacles);
    ~Graph();

    Node *nodes[NODES_ARRAY_SIZE][NODES_ARRAY_SIZE];

    void update(const QList<Entity *> &obstacles);

    // Dej mi node, která nejlépe odpovídá této pozici
    Node *gimmeNode(QPointF pos);

    // Defaultuje visited a parent
    void resetNodes();
};

// Breadth-first search
namespace bfs {
    QList<QPointF> shortestPath(Graph &graph, Node *start, Node *goal);
    QList<QPointF> shortestPath(Graph &graph, QPointF a, QPointF b);
}

#endif // GRAPH_H
