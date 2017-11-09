#ifndef HUMANTOWNHALLUI_HPP
#define HUMANTOWNHALLUI_HPP

#include <QWidget>
#include "Player.hpp"
#include "entity/building/HumanTownHall.hpp"

namespace Ui {
class HumanTownHallUI;
}

class HumanTownHallUI : public QWidget
{
    Q_OBJECT

public:
     explicit HumanTownHallUI(Player *player, ResourceManager *rm, Graph *graph, QGraphicsScene *scene, QWidget *parent = nullptr);
    ~HumanTownHallUI();

    void setHumanTownHall(HumanTownHall *hall);
    void updateUI();

private slots:
    void on_peasantButton_clicked();

private:
    ResourceManager *rm;
    Player *player;
    QGraphicsScene *scene;
    Graph *graph;

    HumanTownHall *hall = nullptr;

    Ui::HumanTownHallUI *ui;


};

#endif // HUMANTOWNHALLUI_HPP
