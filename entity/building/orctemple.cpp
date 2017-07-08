#include "orctemple.h"

OrcTemple::OrcTemple(QPointF pos, bool finishedOnSpawn, Resources &res) :
    Building(pos, finishedOnSpawn, ORC, QList<int>() << 3 << 2, QList<int>() << 2 << 2, BUILD_TIME,HP, res)
{

}

QRectF OrcTemple::boundingRect() const
{
    return QRectF(0,0,92,92);
}

void OrcTemple::update()
{

}
