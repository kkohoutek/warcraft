#ifndef BUILDING_H
#define BUILDING_H

#include "entity/entity.h"
#include "common.h"
#include "animation.h"
#include <QPixmap>
#include <QObject>
/*

*/

class Building : public Entity, public QObject
{
public:
    // preFrame - předposlední snímek animace, endFrame - poslední snímek
    Building(QPointF pos, bool finishedOnSpawn, Race race, QList<int> preFrame, QList<int> endFrame, int buildTime, int maxHP);
    virtual ~Building();

    virtual void update() override;

    void beginConstruction();

    bool isBuildingFinished();

private:
    int buildTime;
    Animation *buildAnimation;
    QTimer *buildTimer;

private slots:
    void constructionUpdate();


};

#endif // BUILDING_H
