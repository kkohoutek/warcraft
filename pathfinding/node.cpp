#include "node.h"

Node::Node() {
    parent = NULL;
    neighbors.reserve(4);
}


Node::Node(int x, int y) : Node() {
    pos.setX(x);
    pos.setY(y);
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
