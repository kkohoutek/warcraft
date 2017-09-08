#include "graph.h"
#include <QLineF>
#include <QQueue>
#include <QDebug>

Graph::Graph() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            nodes[i][j] = new Node((j+1)*NODES_DISTANCE, (i+1)*NODES_DISTANCE);
        }
    }
}

Graph::Graph(const QList<Entity *> &obstacles) : Graph() {
    update(obstacles);
}


Graph::~Graph() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            delete nodes[i][j];

        }
    }
}

void Graph::update(const QList<Entity *> &obstacles) {
    // Delete nodes that intersect obstacles
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            bool interr = false;
            for(int k = 0;  !interr && k < obstacles.size(); k++){
                if(obstacles.at(k)->boundingRect2().contains((j+1)*NODES_DISTANCE, (i+1)*NODES_DISTANCE)){
                    delete nodes[i][j];
                    nodes[i][j] = nullptr;
                    interr = true;
                } else {
                    delete nodes[i][j];
                    nodes[i][j] = new Node((j+1)*NODES_DISTANCE, (i+1)*NODES_DISTANCE);
                }
            }
        }
    }
    // Find each node's neighbors
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *node = nodes[i][j];
            if(node) {
                // Reset neighbors
                for(Node *n : node->neighbors){
                    n = nullptr;
                }

                if(i < NODES_ARRAY_SIZE){
                    node->neighbors[0] = nodes[i+1][j];
                }
                if(i > 0) {
                    node->neighbors[1] = nodes[i-1][j];
                }
                if(j < NODES_ARRAY_SIZE){
                    node->neighbors[2] = nodes[i][j+1];
                }
                if(j > 0){
                    node->neighbors[3] = nodes[i][j-1];
                }
            }
        }
    }
}


QList<QPointF> Graph::BFS_shortestPath(Node *start, Node *goal) {
    if(!goal || !start) return QList<QPointF>();

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
    // Retrace path
    QList<QPointF> path;
    while(node){
        path.append(node->pos);
        node = node->parent;
    }
    resetNodes();
    for(int k = 0; k < (path.size()/2); k++) path.swap(k,path.size()-(1+k)); // reverse list

    return path;
}


QList<QPointF> Graph::BFS_shortestPath(QPointF a, QPointF b) {
    return BFS_shortestPath(gimmeNode(a), gimmeNode(b));
}


Node *Graph::gimmeNode(QPointF pos) {
    // Get indices based on pos and keep indices within bounds
    int i = qBound(0, qRound(pos.y()/NODES_DISTANCE)-1, NODES_ARRAY_SIZE-1);
    int j = qBound(0, qRound(pos.x()/NODES_DISTANCE)-1, NODES_ARRAY_SIZE-1);
    return nodes[i][j];
}

void Graph::resetNodes() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *n = nodes[i][j];
            if(n){
                n->visited = false;
                n->parent = nullptr;
            }
        }
    }
}

