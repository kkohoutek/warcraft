#ifndef PEASANTUI_HPP
#define PEASANTUI_HPP

#include <QWidget>
#include "Player.hpp"

class PeasantUI : public QWidget
{
    Q_OBJECT
public:
    explicit PeasantUI(Building **buildingPtr, Player *player, ResourceManager *rm, QGraphicsScene *scene, QWidget *parent = nullptr);

    void cancelOption();

private:
    // Pointer na pointer na budovu kterou chce hráč stavět
    Building        **buildingPtr;
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
