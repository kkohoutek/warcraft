#ifndef BUILDING_H
#define BUILDING_H

#include "entity/entity.h"
#include "common.h"
#include "animation.h"
#include "resourcemanager.h"
#include <QPixmap>
#include <QObject>


class Building : public QObject, public Entity
{
    Q_OBJECT
public:
    // preFrame - předposlední snímek animace, endFrame - poslední snímek
    Building(QPointF pos, bool finishedOnSpawn, Race race, QList<int> preFrame, QList<int> endFrame, int buildTime, int maxHP, ResourceManager *rm);
    virtual ~Building();

    virtual void update() override;

    void beginConstruction();

    bool isBuildingFinished() const;

private:
    int buildTime;
    Animation *buildAnimation;
    QTimer *buildTimer = NULL;

    bool finished;
private slots:
    void constructionUpdate();


};

#endif // BUILDING_H
