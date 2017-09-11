#include "orctemple.h"

OrcTemple::OrcTemple(QPointF pos, bool finishedOnSpawn, ResourceManager*rm) :
    Building(pos, O_TEMPLE, finishedOnSpawn, ORC, QList<int>() << 3 << 2, QList<int>() << 2 << 2, BUILD_TIME,HP, rm)
{

}

QRectF OrcTemple::boundingRect() const
{
    return QRectF(0,0,92,92);
}
