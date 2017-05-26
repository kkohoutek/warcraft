#ifndef BUILDING_H
#define BUILDING_H

#include "entity/entity.h"
#include <QPixmap>

/*

*/

class Building : public Entity
{
    Q_ENUMS(BuildingType)

public:
    enum BuildingType {
                        GOLDMINE,
                        H_BARRACKS,
                        H_BLACKSMITH,
                        H_CHURCH,
                        H_FARM,
                        H_MILL,
                        H_STABLES,
                        H_TOWER,
                        H_TOWNHALL,
                        O_BLACKSMITH,
                        O_FARM,
                        O_TEMPLE,
                        O_TOWNHALL,
                        O_MILL,
                        O_KENNELS,
                        O_BARRACKS,
                        O_TOWER
                      };

    static const int H_FARM_COST_GOLD = 500;
    static const int H_FARM_COST_LUMBER = 300;
    static const int H_FARM_BUILDTIME = 500000;


    Building(QPointF pos, BuildingType);
    ~Building();

    void update() override;

    bool isBuildingFinished();

private:
    int buildTime;
    Animation *buildAnimation;


};

#endif // BUILDING_H
