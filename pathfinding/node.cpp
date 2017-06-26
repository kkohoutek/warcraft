#include "node.h"

Node::Node(int x, int y, Node *parent) {
    pos = new QPointF(x,y);
    neighbors = new QList<Node *>();
    this->parent = parent;
}

Node::~Node(){
    //delete neighbors;
    //delete pos;
}


void Node::addNeighbor(Node *n){
    neighbors->append(n);
}

void Node::setParent(Node *n){
    parent = n;
}

Node *Node::getParent() {
    return parent;
}

QList<Node *> Node::getNeighbors(){
    return *neighbors;
}

