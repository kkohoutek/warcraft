#ifndef PEASANTUI_HPP
#define PEASANTUI_HPP

#include <QWidget>
#include "Player.hpp"

class PeasantUI : public QWidget
{
    Q_OBJECT
public:
    explicit PeasantUI(Building *&buildingPtr, Player *player, ResourceManager *rm, QGraphicsScene *scene, QWidget *parent = nullptr);

private:
    // Pointer na pointer na budovu kterou chce hráč stavět
    Building **buildingPtr = nullptr;
    ResourceManager *rm;
    Player *player;
    QGraphicsScene *scene;

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
