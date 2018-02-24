#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP

#include <QLinkedList>
#include "entity/Entity.hpp"

#define PATH QQueue<Node **>
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
    // Sestrojí graf se všemi nodes null
    Graph();
    // Sestrojí graf a zavolá update
    Graph(const QLinkedList<Entity *> &obstacles);
    ~Graph();

    // Aktualizuje graf podle listu překážek
    void update(const QLinkedList<Entity *> &obstacles);

    /* Vrátí pointer na pointer z pole nodes, který ukazuje na node se stejnou pos;
       pokud noNull, bere nejbližší shodu pos. */
    Node **gimmeNode(const QPointF &pos, bool noNull = false);

    // Defaultuje visited a parent
    void resetNodes() const;

    Node *node(int i, int j) const;

    PATH shortestPath(Node *start, Node *goal);
    PATH shortestPath(QPointF a, QPointF b);

    static QPointF posFromIndices(int i, int j);

private:
    Node *nodes[NODES_ARRAY_SIZE][NODES_ARRAY_SIZE];
};

bool isPathValid(const PATH &path);
PATH reversePath(PATH path);

#endif // PATHFINDING_HPP
