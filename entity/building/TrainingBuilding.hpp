#ifndef TRAININGBUILDING_HPP
#define TRAININGBUILDING_HPP

#include <QQueue>
#include <QTimer>
#include "Building.hpp"
#include "entity/unit/Unit.hpp"

#define TRAINING_QUEUE_CAP 4

class TrainingBuilding : public Building
{
    Q_OBJECT
public:
    TrainingBuilding(QPointF pos, Building::Type type, bool finishedOnSpawn, Race race, const QList<int> &preFrame, const QList<int> &endFrame, int buildTime, int maxHP, ResourceManager *rm);
    virtual ~TrainingBuilding();

    bool enqueueUnit(Unit *unit, int sec);
    int unitsInQueue() const;
    virtual bool isQueueFull() const;

protected:
    QQueue<Unit *> trainingQueue;
    QTimer trainingTimer;

protected slots:
    void dequeueUnit();

};

#endif // TRAININGBUILDING_HPP
