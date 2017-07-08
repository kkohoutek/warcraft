#include "node.h"

Node::Node(int x, int y) {
    pos.setX(x);
    pos.setY(y);
    parent = NULL;
}


void Node::addNeighbor(Node *n){
    if(!neighbors.contains(n)){
        neighbors.append(n);
    }
}

void Node::setParent(Node *n){
    parent = n;
}

Node *Node::getParent() {
    return parent;
}

QList<Node *> Node::getNeighbors(){
    return neighbors;
}

