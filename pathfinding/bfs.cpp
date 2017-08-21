#include "bfs.h"
#include <QQueue>
#include <QDebug>

BFS::BFS(Graph *graph, Node *start, Node *goal) {
    this->graph = graph;
    this->start = start;
    this->goal = goal;
}

BFS::BFS() {
    graph = NULL;
    start = NULL;
    goal = NULL;
}

void BFS::setGraph(Graph *graph){
    this->graph = graph;
}

void BFS::setStart(Node *node) {
    start = node;

}

void BFS::setGoal(Node *node) {
    goal = node;

}

QList<Node *> BFS::shortestPath() {
    // breadth-first search

    QQueue<Node *> queue;
    queue.enqueue(start);

    Node *node = NULL;
    while(!queue.empty()){
        node = queue.dequeue();
        if(node == goal) break; // ???

        for(Node *neighbor : node->getNeighbors()){
            if(!neighbor->visited){
                queue.enqueue(neighbor);
                neighbor->visited = true;
                neighbor->setParent(node);

            }
        }
    }

    // retrace
    QList<Node *> path;
    while(node != start){
        path.append(node);
        node = node->getParent();

    }
    path.append(start);


    for(int k = 0; k < (path.size()/2); k++) path.swap(k,path.size()-(1+k)); // reverse list
    return path;
}
