#include "orctemple.h"

OrcTemple::OrcTemple(QPointF pos, bool finishedOnSpawn) :
    Building(pos, finishedOnSpawn, ORC, QList<int>() << 3 << 2, QList<int>() << 2 << 2, BUILD_TIME,HP)
{

}

QRectF OrcTemple::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void OrcTemple::update()
{

}