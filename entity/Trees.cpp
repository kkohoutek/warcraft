#include "Trees.hpp"

Trees::Trees(QPointF pos) : Entity(pos){

}

QRectF Trees::boundingRect() const {
    return QRectF(0,0,192,192);

}
