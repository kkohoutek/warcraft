#ifndef DAEMON_HPP
#define DAEMON_HPP

#include "Unit.hpp"
#include "ResourceManager.hpp"

class Daemon : public Unit
{
public:
    Daemon(QPointF pos, ResourceManager *rm);
public:
    QRectF boundingRect() const override;
};

#endif // DAEMON_HPP
