#include "graph.h"
#include <QLineF>
#include <QDebug>


Graph::Graph(){
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            nodes[j][i] = NULL;
        }
    }
}

Graph::~Graph() {
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++){
            delete nodes[j][i];
        }
    }
}

Node *Graph::gimmeNode(QPointF pos) {
    Node *nearestNode = NULL;
    float minLength = std::numeric_limits<float>::max();

    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 64; j++) {
            Node *node = nodes[j][i];
            if(node != NULL){
                float length = QLineF(node->pos, pos).length();
                if(length < minLength){
                    minLength = length;
                    nearestNode = node;
                }
            }
        }
    }
    return nearestNode;
}


