#ifndef TRAININGBUILDING_HPP
#define TRAININGBUILDING_HPP

#include <QQueue>
#include <QTimer>
#include "Building.hpp"
#include "Player.hpp"
#include "entity/unit/Unit.hpp"

class TrainingBuilding : public Building
{
    Q_OBJECT
public:
    TrainingBuilding(QPointF pos, Building::Type type, bool finishedOnSpawn, Race race, const QList<int> &preFrame, const QList<int> &endFrame, int buildTime, int maxHP, ResourceManager *rm, Player *player);
    virtual ~TrainingBuilding();

    bool enqueueUnit(Unit *unit, int sec);
    int unitsInQueue() const;
    virtual bool isQueueFull() const;

    void die() override;

protected:
    QQueue<Unit *> trainingQueue;
    QTimer trainingTimer;
    Player *player;

protected slots:
    void dequeueUnit();
};

#endif // TRAININGBUILDING_HPP
