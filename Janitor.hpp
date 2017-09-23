#ifndef JANITOR_HPP
#define JANITOR_HPP

#include "Warcraft.hpp"

class Janitor : public QObject
{
    Q_OBJECT
public:
    explicit Janitor(Warcraft *game);

public slots:
    void update();

private:
    QQueue<Entity **> delQueue;
    QTimer updateTimer;

    Warcraft *game;
};

#endif // JANITOR_HPP
