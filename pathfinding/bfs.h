#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <QList>

class BFS
{
public:
    BFS(Graph *graph, Node *start, Node *goal);
    BFS();
    ~BFS();

    void setStart(Node *node);
    void setGoal(Node *node);
    void setGraph(Graph *graph);

    QList<QPointF> shortestPath();


private:
    Graph *graph;
    Node *start;
    Node *goal;
};

#endif // BFS_H
