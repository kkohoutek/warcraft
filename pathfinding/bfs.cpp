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

BFS::~BFS() {
    //delete graph;
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

QList<QPointF> BFS::shortestPath() {
    // breadth-first search
    QList<Node *> nodes = graph->getNodes();

    QQueue<int> queue;
    queue.enqueue(nodes.indexOf(start));

    int nodeIndex;
    while(!queue.empty()){
        nodeIndex = queue.dequeue();
        for(Node *neighbor : nodes.at(nodeIndex)->getNeighbors()){
            if(!neighbor->visited){
                queue.enqueue(nodes.indexOf(neighbor));
                neighbor->visited = true;
                neighbor->setParent(nodes.at(nodeIndex));
            }
        }
    }

    QList<QPointF> path;
    Node *node = nodes.at(nodeIndex);
    while(node != start){
        path.append(*(node->pos));
        node = node->getParent();

    }

    for(int k = 0; k < (path.size()/2); k++) path.swap(k,path.size()-(1+k));
    return path;
}
