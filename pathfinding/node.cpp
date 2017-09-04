#include "node.h"

Node::Node(int x, int y) {
    pos.setX(x);
    pos.setY(y);
    parent = NULL;
}

Node::Node() {
    parent = NULL;
}

void Node::addNeighbor(Node *n){
    neighbors.append(n);
}

void Node::setParent(Node *n){
    parent = n;
}

Node *Node::getParent() {
    return parent;
}

QList<Node *> Node::getNeighbors() {
    return neighbors;
}
