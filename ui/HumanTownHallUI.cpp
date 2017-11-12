#include "HumanTownHallUI.hpp"
#include "ui_HumanTownHallUI.h"

#include "entity/unit/Worker.hpp"

HumanTownHallUI::HumanTownHallUI(Player *player, ResourceManager *rm, Graph *graph, QGraphicsScene *scene, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HumanTownHallUI)
{
    this->player = player;
    this->rm = rm;
    this->scene = scene;
    this->graph = graph; 
    setGeometry(650,520,200,200);

    ui->setupUi(this);
}

HumanTownHallUI::~HumanTownHallUI() {
    delete ui;
}

void HumanTownHallUI::setHumanTownHall(HumanTownHall *hall) {
    this->hall = hall;
}

void HumanTownHallUI::updateUI() {
    ui->count->setText(QString::number(hall->unitsInQueue()));
}

void HumanTownHallUI::on_peasantButton_clicked() {
    if(!hall || hall->isQueueFull() || player->food == 0 || player->gold < Worker::COST_GOLD || Worker::COST_LUMBER) return;

    Worker *w = new Worker(hall->center(),Unit::PEASANT,player,rm);
    w->useGraph(graph);
    hall->enqueueUnit(w, 3);
    player->food--;
    player->gold -= Worker::COST_GOLD;
    player->lumber -= Worker::COST_LUMBER;

    updateUI();

}
