#ifndef HUMANBARRACKSUI_HPP
#define HUMANBARRACKSUI_HPP

#include <QWidget>
#include "Player.hpp"
#include "entity/building/HumanBarracks.hpp"

namespace Ui {
class HumanBarracksUI;
}

class HumanBarracksUI : public QWidget
{
    Q_OBJECT

public:
    explicit HumanBarracksUI(Player *player, ResourceManager *rm, Graph *graph, QGraphicsScene *scene, QWidget *parent = 0);
    ~HumanBarracksUI();

    void setHumanBarracks(HumanBarracks *barracks);
    void updateUI();

private slots:
    void on_footmanButton_clicked();

private:
    ResourceManager *rm;
    Player *player;
    QGraphicsScene *scene;
    Graph *graph;

    HumanBarracks *barracks = nullptr;

    Ui::HumanBarracksUI *ui;
};

#endif // HUMANBARRACKSUI_HPP
