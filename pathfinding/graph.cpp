#include "graph.h"
#include <QLineF>
#include <QDebug>


Graph::Graph(){}

Graph::~Graph() {
    for(Node *n : nodes){
        delete n;
    }
}

void Graph::addNode(qreal x, qreal y) {
    nodes.append(new Node(x,y));
}

Node *Graph::getNodeByPos(qreal x, qreal y){
    for(Node *node : nodes){
        if(x == node->pos.x() && y == node->pos.y()){
            return node;
        }
    }

    return NULL;
}

Node *Graph::getClosestNode(qreal x, qreal y){
    for(Node *node : nodes){
        qDebug() << node->pos;
        if(QLineF(QPointF(x,y),node->pos).length() == 48){
            return node;
        }
    }
    return NULL;
}

QList<Node *> &Graph::getNodes(){
    return nodes;
}
