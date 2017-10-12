#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP

#include <QLinkedList>
#include "entity/Entity.hpp"

#define GRAPH_MARGIN        2
#define GRAPH_SPACING       32  // Rozestup uzlů horizontálně a vertikálně
#define NODES_ARRAY_SIZE    2048/GRAPH_SPACING-GRAPH_MARGIN-GRAPH_MARGIN/2

struct Node {
    Node(int x, int y) { pos.setX(x); pos.setY(y); }
    bool            visited = false;
    QPointF         pos;
    Node            *neighbors[8] = {nullptr};
    Node            *parent = nullptr;
};

class Graph
{
public:
    Node *nodes[NODES_ARRAY_SIZE][NODES_ARRAY_SIZE];

    // Sestrojí graf se všemi nodes null
    Graph();
    // Sestrojí graf a zavolá update
    Graph(const QLinkedList<Entity *> &obstacles);
    ~Graph();

    // Aktualizuje graf podle listu překážek
    void update(const QLinkedList<Entity *> &obstacles);

    /* Dej sem node, která nejlépe odpovídá tomuto bodu
       Pokud noNull, vrátí node, která je nejblíž */
    Node **gimmeNode(QPointF pos, bool noNull = false);

    // Defaultuje visited a parent
    void resetNodes() const;

private:
    static QPointF posFromIndices(int i, int j);
};

// Breadth-first search
namespace bfs {
    QLinkedList<Node **> shortestPath(Graph &graph, Node *start, Node *goal);
    QLinkedList<Node **> shortestPath(Graph &graph, QPointF a, QPointF b);
}

#endif // PATHFINDING_HPP
