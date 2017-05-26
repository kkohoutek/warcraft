#include "building.h"


Building::Building(QPointF pos, BuildingType type) : Entity(pos, NULL, 48, 48)
{

    QList<QList<int>> *frames = new QList<QList<int>>();;

    // v budoucnu: list s trénovatelnými typy jednotek, list s právě trénovanými jednotkami


    QPixmap *human = new QPixmap("../wc/res/BUILDINGS_H_edit.png");
    QPixmap *orc = new QPixmap("../wc/res/BUILDINGS_O_edit.png");

    switch(type){

    // HUMANS

    case H_FARM:
        spriteSheet = human;
        buildTime = H_FARM_BUILDTIME;

        frames->append(QList<int>() << 0 << 0);
        frames->append(QList<int>() << 1 << 0);
        frames->append(QList<int>() << 1 << 1);
        frames->append(QList<int>() << 0 << 1);


        break;

    case H_BLACKSMITH:
        spriteSheet = human;

        buildTime = 10000;
        setHP(400);

        frames->append(QList<int>() << 0 << 0);
        frames->append(QList<int>() << 1 << 0);
        frames->append(QList<int>() << 3 << 0);
        frames->append(QList<int>() << 2 << 0);



        break;


    case H_TOWER:
        spriteSheet = human;


        break;

    case H_BARRACKS:
        spriteSheet = human;


        break;

    case H_STABLES:
        spriteSheet = human;


        break;



    case H_TOWNHALL:
        spriteSheet = human;

        break;

    case H_MILL:
        spriteSheet = human;

        break;

    case H_CHURCH:
        spriteSheet = human;

        break;


    // ORCS

    case O_FARM:
        spriteSheet = orc;


        break;

    }

    buildAnimation = new Animation(48,48,frames, buildTime/frames->size(), false);
    setCurrentAnimation(buildAnimation);


}

Building::~Building()
{

}

void Building::update(){

}

bool Building::isBuildingFinished()
{
    return !buildAnimation->getTimer()->isActive();
}
