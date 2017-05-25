#ifndef BUILDING_H
#define BUILDING_H

#include "entity/entity.h"
//#include "entity/unit/unit.h"



class Building : public Entity
{
public:
    Building();

    enum BuildingType {H_BARRACKS, H_FARM};

    // Entity interface
    void update() override;


private:
    QPixmap *buildAnimation;

    QList<BuildingType> *unitsAvailable;
    QList<BuildingType> *unitsTrained;

    QTimer *trainingTimer;
    QTimer *buildTimer;
};

#endif // BUILDING_H
