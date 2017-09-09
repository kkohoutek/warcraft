#ifndef BUILDING_H
#define BUILDING_H

#include "entity/entity.h"
#include "common.h"
#include "animation.h"
#include "resourcemanager.h"
#include <QPixmap>
#include <QObject>

enum BuildingType {
    H_BARRACKS,
    H_BLACKSMITH,
    H_CHURCH,
    H_FARM,
    H_LUMBERMILL,
    H_STABLES,
    H_TOWER,
    H_TOWNHALL,

    O_BARRACKS,
    O_BLACKSMITH,
    O_FARM,
    O_KENNELS,
    O_LUMBERMILL,
    O_TEMPLE,
    O_TOWER,
    O_TOWNHALL
};

class Building : public QObject, public Entity
{
    Q_OBJECT
public:
    // preFrame - předposlední snímek animace, endFrame - poslední snímek
    Building(QPointF pos, BuildingType type, bool finishedOnSpawn, Race race, QList<int> preFrame, QList<int> endFrame, int buildTime, int maxHP, ResourceManager *rm);
    virtual ~Building();

    virtual void update() override;
    bool isBuildingFinished() const;
    BuildingType getType() const;

private:
    BuildingType type;
    int buildTime;
    Animation *buildAnimation;
    QTimer *buildTimer = nullptr;

    bool finished;

private slots:
    void constructionUpdate();


};

#endif // BUILDING_H
