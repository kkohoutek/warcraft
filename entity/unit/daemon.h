#ifndef DAEMON_H
#define DAEMON_H

#include "unit.h"

class Daemon : public Unit
{
public:
    Daemon(QPointF pos);
public:
    QRectF boundingRect() const override;
};

#endif // DAEMON_H
