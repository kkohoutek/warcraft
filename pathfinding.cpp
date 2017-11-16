#include "pathfinding.hpp"
#include <QQueue>
#include <QDebug>

#define NODE_NEIGHBORS_LIMIT 8   // S kolika sousedy počítáme (max 8)

Graph::Graph() {
    std::memset(nodes, 0, sizeof(nodes));
}

Graph::Graph(const QLinkedList<Entity *> &obstacles) : Graph() {
    update(obstacles);
}

Graph::~Graph() {
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            delete nodes[i][j];
        }
    }
}

void Graph::update(const QLinkedList<Entity *> &obstacles) {
    // Smaž nodes které jsou překryty překážkami
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            bool interr = false;
            for(Entity * obstacle : obstacles){
                if(!interr){
                    auto pos = posFromIndices(i, j);
                    if(obstacle->boundingRect2().contains(pos.x(), pos.y())){
                        delete nodes[i][j];
                        nodes[i][j] = nullptr;
                        interr = true;
                    } else if(!nodes[i][j]){
                        nodes[i][j] = new Node(pos.x(), pos.y());
                    }
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
                std::memset(node->neighbors, 0, 8 * sizeof(Node *));

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

                /* Diagonálně */

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

Node **Graph::gimmeNode(const QPointF &pos, bool noNull) {
    // Získej indexy podle pozice a udrž je v rozsahu arraye
    int i = qBound(0, qRound(pos.y()/GRAPH_SPACING)-GRAPH_MARGIN, NODES_ARRAY_SIZE-1);
    int j = qBound(0, qRound(pos.x()/GRAPH_SPACING)-GRAPH_MARGIN, NODES_ARRAY_SIZE-1);

    Node **result = &(nodes[i][j]);

    if(noNull && !*result){
        // Najdi nejbližší
        float minLength = std::numeric_limits<float>::max();
        for(int i = 0; i < NODES_ARRAY_SIZE; i++){
            for(int j = 0; j < NODES_ARRAY_SIZE; j++) {
                Node **node = &(nodes[i][j]);
                if(*node){
                    float length = QLineF(pos, (*node)->pos).length();
                    if(length < minLength){
                        minLength = length;
                        result = node;
                    }
                }
            }
        }
    }
    return result;
}

void Graph::resetNodes() const {
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

Path Graph::shortestPath(Node *start, Node *goal) {
    if(!goal || !start) return Path();

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
    Path path;
    while(node != start){
        path.prepend(gimmeNode(node->pos));
        node = node->parent;
    }
    resetNodes();

    return path;
}


Path Graph::shortestPath(QPointF a, QPointF b) {
    return shortestPath(*(gimmeNode(a, true)), *(gimmeNode(b, true)));
}


QPointF Graph::posFromIndices(int i, int j) {
    return QPointF((j+GRAPH_MARGIN)*GRAPH_SPACING, (i+GRAPH_MARGIN)*GRAPH_SPACING);
}

bool isPathValid(const Path &path) {
    for(Node **n : path){
        if(*n == nullptr){
            return false;
        }
    }
    return true;
}

Path reversePath(Path path) {
    for(int i = 0; i < (path.size()/2); i++) path.swap(i,path.size()-(1+i));
    return path;
}
