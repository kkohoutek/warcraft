#include "node.h"

Node::Node() {
    parent = nullptr;
    visited = false;
    neighbors.reserve(4);     // 4 neighbors
}


Node::Node(const int x, const int y) : Node() {
    pos.setX(x);
    pos.setY(y);
}

void Node::addNeighbor(Node *n){
    neighbors.append(n);
}

void Node::setParent(Node *n){
    parent = n;
}

Node *Node::getParent() const {
    return parent;
}

const QVector<Node *> &Node::getNeighbors() const {
    return neighbors;
}
