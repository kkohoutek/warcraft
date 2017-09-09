#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "entity/entity.h"

#define SPACING 32
#define NODES_ARRAY_SIZE 2048/SPACING-2

struct Node {
    Node(const int x, const int y) { pos.setX(x); pos.setY(y); }
    bool                visited = false;
    QPointF             pos;
    Node                *neighbors[8] = {nullptr};
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

#endif // PATHFINDING_H
