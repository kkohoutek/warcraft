#include "graph.h"
#include <QLineF>
#include <QDebug>
#include <QGraphicsScene>

Graph::Graph() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            nodes[i][j] = new Node((j+1)*NODES_DISTANCE, (i+1)*NODES_DISTANCE);
        }
    }
}

Graph::Graph(QList<Entity *> obstacles) : Graph() {
    // nodes that intersect static entities will be nullptr

    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
                for(Entity *entity : obstacles){
                    if(entity->boundingRect2().contains((j+1)*NODES_DISTANCE, (i+1)*NODES_DISTANCE)){
                        delete nodes[i][j];
                        nodes[i][j] = nullptr;
                    }
                }
        }
    }

    // determine neighbors (4) of each node
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *node = nodes[i][j];
            if(node != nullptr) {
                if(i > 0) {
                    node->addNeighbor(nodes[i-1][j]);
                }
                if(i < NODES_ARRAY_SIZE){
                    node->addNeighbor(nodes[i+1][j]);
                }
                if(j > 0){
                    node->addNeighbor(nodes[i][j-1]);
                }
                if(j < NODES_ARRAY_SIZE){
                    node->addNeighbor(nodes[i][j+1]);
                }
            }
        }
    }
}


Graph::~Graph() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            delete nodes[i][j];
        }
    }
}

Node *Graph::gimmeNode(QPointF pos) {
    Node *nearestNode = nullptr;
    /*
    float minLength = std::numeric_limits<float>::max();

    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++) {
            Node *node = nodes[i][j];
            if(node != nullptr){
                float length = QLineF(pos, node->pos).length();
                if(length < minLength){
                    minLength = length;
                    nearestNode = node;
                }
            }
        }
    }*/
    nearestNode = nodes[qRound(pos.y()/NODES_DISTANCE)-1][qRound(pos.x()/NODES_DISTANCE)-1];
    return nearestNode;
}

void Graph::resetNodes() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *n = nodes[i][j];
            if(n != nullptr){
                n->visited = false;
                n->setParent(nullptr);
            }
        }
    }
}

