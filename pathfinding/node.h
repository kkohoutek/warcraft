#ifndef NODE_H
#define NODE_H

#include <QList>
#include <QPointF>

class Node
{
public:
    Node(int x, int y, Node *parent);
    ~Node();

    Node *parent = NULL;   // ze které node jsme přišli
    bool visited;
    QPointF *pos = NULL;


    void addNeighbor(Node *n);
    void setParent(Node *n);
    Node *getParent();

    QList<Node *> getNeighbors();

protected:
    QList<Node *> *neighbors;
};

#endif // NODE_H
