#include "bfs.h"
#include <QQueue>
#include <QDebug>

BFS::BFS() { }

QList<QPointF> BFS::shortestPath(Graph *graph, Node *start, Node *goal) {
    if(!goal) return QList<QPointF>();
    /* Breadth-first search */

    QQueue<Node *> queue;
    start->visited = true;
    queue.enqueue(start);

    Node *node = nullptr;
    while(!queue.isEmpty()){
        node = queue.dequeue();
        if(node == goal) break;

        for(Node *neighbor : node->neighbors){
            if(neighbor && !neighbor->visited){
                queue.enqueue(neighbor);
                neighbor->visited = true;
                neighbor->parent = node;
            }
        }
    }
    // retrace
    QList<QPointF> path;
    while(node){
        path.append(node->pos);
        node = node->parent;
    }

    graph->resetNodes();
    for(int k = 0; k < (path.size()/2); k++) path.swap(k,path.size()-(1+k)); // reverse list
    return path;
}


QList<QPointF> BFS::shortestPath(Graph *graph, QPointF a, QPointF b) {
    return BFS::shortestPath(graph, graph->gimmeNode(a), graph->gimmeNode(b));
}

