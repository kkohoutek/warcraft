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
    ui->setupUi(this);

    this->setGeometry(650,520,200,200);

}

HumanTownHallUI::~HumanTownHallUI() {
    delete ui;
}

void HumanTownHallUI::setHumanTownHall(HumanTownHall *hall) {
    this->hall = hall;
}

void HumanTownHallUI::on_peasantButton_clicked() {
    if(!hall || hall->isQueueFull()) return;

    Worker *w = new Worker(hall->center(),Unit::PEASANT,&(player->gold),&(player->lumber),rm);
    w->useGraph(graph);
    hall->enqueueUnit(w, 3);
    player->getUnits().prepend(w);

}
