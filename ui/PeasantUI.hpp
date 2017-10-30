#ifndef PEASANTUI_HPP
#define PEASANTUI_HPP

#include <QWidget>
#include "Player.hpp"

class PeasantUI : public QWidget
{
    Q_OBJECT
public:
    explicit PeasantUI(Player *player, ResourceManager *rm, QGraphicsScene *scene, QWidget *parent = nullptr);

    void cancelOption();
    void release();
    Building *getCurrentBuilding() const;

private:
    Building        *currentBuilding = nullptr;
    ResourceManager *rm;
    Player          *player;
    QGraphicsScene  *scene;

    void prepare(Building *b);

private slots:
    void clickFarm();
    void clickBarracks();
    void clickHall();
    void clickStables();
    void clickBlacks();
    void clickChurch();
    void clickMill();
};

#endif // PEASANTUI_HPP
