#ifndef DAEMON_H
#define DAEMON_H

#include "unit.h"
#include "resources.h"

class Daemon : public Unit
{
public:
    Daemon(QPointF pos, Resources &res);
public:
    QRectF boundingRect() const override;
};

#endif // DAEMON_H
