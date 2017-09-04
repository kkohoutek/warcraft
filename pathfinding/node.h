#ifndef NODE_H
#define NODE_H

#include <QList>
#include <QPointF>

class Node
{
public:
    Node();
    Node(int x, int y);

    bool                visited;
    QPointF             pos;

    QList<Node *>       getNeighbors();
    void                addNeighbor(Node *n);
    void                setParent(Node *n);
    Node                *getParent();

private:
    Node                *parent;   // ze které node jsme přišli
    QList<Node *>       neighbors;
};

#endif // NODE_H
