#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "entity/Entity.hpp"
#include "Animation.hpp"
#include "ResourceManager.hpp"
#include "Race.hpp"
#include <QObject>


class Building : public QObject, public Entity
{
    Q_OBJECT
public:
    // C++ nemá reflexi, opravte to
    enum Type {
        NONE,

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

    // preFrame - předposlední snímek animace, endFrame - poslední snímek
    Building(QPointF pos, Building::Type type, bool finishedOnSpawn, Race race, const QList<int> &preFrame, const QList<int> &endFrame, int buildTime, int maxHP, ResourceManager *rm);
    virtual ~Building();

    void startConstruction();

    void            die() override;
    bool            isAlive() const override          { return Entity::isAlive() || (getHP() == 0 && !finished); }
    bool            isSelectable() const override     { return Entity::isSelectable() && finished; }
    bool            isBuildingFinished() const        { return finished; }
    Building::Type  getType() const                   { return type; }

protected:
    int buildTime;
    Building::Type type;
    bool finished;

private:
    QTimer *buildTimer = nullptr;

private slots:
    void constructionUpdate();


};

#endif // BUILDING_HPP
