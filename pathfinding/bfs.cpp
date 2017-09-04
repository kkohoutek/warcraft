#include "bfs.h"
#include <QQueue>
#include <QDebug>

BFS::BFS() { }


QList<QPointF> BFS::shortestPath(Node *start, Node *goal) {
    // breadth-first search

    QQueue<Node *> queue;
    queue.enqueue(start);

    Node *node = NULL;
    while(!queue.isEmpty()){
        node = queue.dequeue();
        if(node == goal) break; // ???

        for(Node *neighbor : node->getNeighbors()){
            if(neighbor != NULL && !neighbor->visited){
                queue.enqueue(neighbor);
                neighbor->visited = true;
                neighbor->setParent(node);

            }
        }
    }

    // retrace
    QList<QPointF> path;
    while(node != start){
        path.append(node->pos);
        node = node->getParent();
        qDebug() << node->pos;

    }
    path.append(start->pos);

    for(int k = 0; k < (path.size()/2); k++) path.swap(k,path.size()-(1+k)); // reverse list
    return path;
}
