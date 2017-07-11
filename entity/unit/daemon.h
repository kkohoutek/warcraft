#ifndef DAEMON_H
#define DAEMON_H

#include "unit.h"
#include "resourcemanager.h"

class Daemon : public Unit
{
public:
    Daemon(QPointF pos, ResourceManager *rm);
public:
    QRectF boundingRect() const override;
};

#endif // DAEMON_H
