#include "graph.h"
#include <QLineF>
#include <QDebug>


Graph::Graph() { }

Graph::Graph(QList<Entity *> obstacles){
    qDebug() << NODES_ARRAY_SIZE;
    // nodes that intersect static entities will be NULL
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            for(Entity *entity : obstacles){
                nodes[i][j] = entity->boundingRect2().contains(j*NODES_DISTANCE,i*NODES_DISTANCE) ? NULL : new Node(j*NODES_DISTANCE, i*NODES_DISTANCE);
            }
        }
    }

    qDebug() << obstacles.at(0)->boundingRect2().contains(QPointF(3*32,3*32));

    // determine neighbors (4) of each node
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *node = nodes[i][j];
            if(node != NULL) {
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
    Node *nearestNode = NULL;
    float minLength = std::numeric_limits<float>::max();

    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++) {
            Node *node = nodes[i][j];
            if(node != NULL){
                float length = QLineF(pos, node->pos).length();
                if(length < minLength){
                    minLength = length;
                    nearestNode = node;
                }
            }
        }
    }
    return nearestNode;
}

void Graph::resetNodes() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *n = nodes[i][j];
            if(n != NULL){
                n->visited = false;
                n->setParent(NULL);
            }
        }
    }
}

