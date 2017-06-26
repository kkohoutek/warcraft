#include "graph.h"

Graph::Graph() {
    nodes = new QList<Node *>();
}

Graph::~Graph() {
    /*
    for(Node *n : *nodes){
        delete n;
    }
    delete nodes;*/
}

void Graph::addNode(Node *node) {
    nodes->append(node);
}

Node *Graph::getNodeByPos(int x, int y)
{
    QPointF pos(x,y);

    for(Node *node : *nodes){
        if(*node->pos == pos){
            return node;
        }
    }

    return NULL;
}

QList<Node *> Graph::getNodes(){
    return *nodes;

}
