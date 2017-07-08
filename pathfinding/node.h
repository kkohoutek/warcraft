#ifndef NODE_H
#define NODE_H

#include <QList>
#include <QPointF>

class Node
{
public:
    Node(int x, int y);

    bool                visited;
    QPointF             pos;

    void                addNeighbor(Node *n);
    void                setParent(Node *n);
    QList<Node *>       getNeighbors();
    Node                *getParent();

private:
    QList<Node *>       neighbors;
    Node                *parent;   // ze které node jsme přišli
};

#endif // NODE_H
