#ifndef NODE_H
#define NODE_H

#include <QVector>
#include <QPointF>

class Node
{
public:
    Node();
    Node(const int x, const int y);

    bool                visited;
    QPointF             pos;

    const QVector<Node *>   &getNeighbors() const;
    void                    addNeighbor(Node *n);
    void                    setParent(Node *n);
    Node                    *getParent() const;

private:
    Node                *parent;   // ze které node jsme přišli
    QVector<Node *>     neighbors;
};

#endif // NODE_H
