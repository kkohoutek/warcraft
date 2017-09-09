#include "pathfinding.h"
#include <QQueue>
#include <QDebug>

#define NODE_NEIGHBORS_LIMIT 8   // S kolika sousedy počítáme (max 8)

Graph::Graph() {
    memset(nodes, 0, sizeof(nodes));
}

Graph::Graph(const QList<Entity *> &obstacles) : Graph() {
    update(obstacles);
}

Graph::~Graph() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            delete nodes[i][j];

        }
    }
}

void Graph::update(const QList<Entity *> &obstacles) {
    // Smaž nodes které jsou překryty překážkami
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            bool interr = false;
            for(int k = 0;  !interr && k < obstacles.size(); k++){
                if(obstacles[k]->boundingRect2().contains((j+2)*SPACING, (i+2)*SPACING)){
                    delete nodes[i][j];
                    nodes[i][j] = nullptr;
                    interr = true;
                } else {
                    delete nodes[i][j];
                    nodes[i][j] = new Node((j+2)*SPACING, (i+2)*SPACING);
                }
            }
        }
    }
    // Najdi sousedy pro každou node
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *node = nodes[i][j];
            if(node) {
                // Vynulluj sousedy
                memset(node->neighbors, 0, 8 * sizeof(Node *));

                if(i + 1 < NODES_ARRAY_SIZE){
                    node->neighbors[0] = nodes[i+1][j];
                }
                if(i - 1 >= 0) {
                    node->neighbors[1] = nodes[i-1][j];
                }
                if(j + 1 < NODES_ARRAY_SIZE){
                    node->neighbors[2] = nodes[i][j+1];
                }
                if(j - 1 >= 0){
                    node->neighbors[3] = nodes[i][j-1];
                }

                // Diagonálně

                if(i - 1 >= 0 && j - 1 >= 0){
                    node->neighbors[4] = nodes[i-1][j-1];
                }
                if(j + 1 < NODES_ARRAY_SIZE && i - 1 >= 0){
                    node->neighbors[5] = nodes[i-1][j+1];
                }
                if(i + 1 < NODES_ARRAY_SIZE && j + 1 < NODES_ARRAY_SIZE){
                    node->neighbors[6] = nodes[i+1][j+1];
                }
                if(i + 1 < NODES_ARRAY_SIZE && j - 1 >= 0){
                    node->neighbors[7] = nodes[i+1][j-1];
                }

            }
        }
    }
}

Node *Graph::gimmeNode(QPointF pos) {
    // Získej indexy podle pozice a udrž je v rozsahu arraye
    int i = qBound(0, qRound(pos.y()/SPACING)-2, NODES_ARRAY_SIZE-1);
    int j = qBound(0, qRound(pos.x()/SPACING)-2, NODES_ARRAY_SIZE-1);

    if(!nodes[i][j]){

    }

    return nodes[i][j];
}

void Graph::resetNodes() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *n = nodes[i][j];
            if(n){
                n->visited = false;
                n->parent = nullptr;
            }
        }
    }
}



QList<QPointF> bfs::shortestPath(Graph &graph, Node *start, Node *goal) {
    if(!goal || !start) return QList<QPointF>();

    QQueue<Node *> queue;
    start->visited = true;
    queue.enqueue(start);

    Node *node = nullptr;
    while(!queue.isEmpty()){
        node = queue.dequeue();
        if(node == goal) break;

        for(int i = 0; i < NODE_NEIGHBORS_LIMIT; i++){
            Node *neighbor = node->neighbors[i];
            if(neighbor && !neighbor->visited){
                queue.enqueue(neighbor);
                neighbor->visited = true;
                neighbor->parent = node;
            }
        }
    }
    // Retrace
    QList<QPointF> path;
    while(node){
        path.append(node->pos);
        node = node->parent;
    }
    graph.resetNodes();
    for(int k = 0; k < (path.size()/2); k++) path.swap(k,path.size()-(1+k)); // Reverse list

    return path;
}


QList<QPointF> bfs::shortestPath(Graph &graph, QPointF a, QPointF b) {
    return bfs::shortestPath(graph, graph.gimmeNode(a), graph.gimmeNode(b));
}

