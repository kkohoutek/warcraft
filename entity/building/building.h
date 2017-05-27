#ifndef BUILDING_H
#define BUILDING_H

#include "entity/entity.h"
#include "common.h"
#include <QPixmap>

/*

*/

class Building : public Entity, public QObject
{
public:
    // preFrame - předposlední snímek animace, endFrame - poslední snímek
    Building(QPointF pos, bool finishedOnSpawn, Race race, QList<int> preFrame, QList<int> endFrame, int width, int height, int buildTime, int maxHP);
    ~Building();

    virtual void update() override;

    bool isBuildingFinished();

private:
    int buildTime;
    Animation *buildAnimation;

    QTimer *buildTimer;

private slots:
    void constructionUpdate();


};

#endif // BUILDING_H
