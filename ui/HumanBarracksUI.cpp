#include "HumanBarracksUI.hpp"
#include "ui_HumanBarracksUI.h"

#include "entity/unit/Footman.hpp"

HumanBarracksUI::HumanBarracksUI(Player *player, ResourceManager *rm, Graph *graph, QGraphicsScene *scene, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HumanBarracksUI)
{
    this->rm = rm;
    this->graph = graph;
    this->scene = scene;
    this->player = player;
    setGeometry(650,520,200,200);
    ui->setupUi(this);
}

HumanBarracksUI::~HumanBarracksUI() {
    delete ui;
}

void HumanBarracksUI::setHumanBarracks(HumanBarracks *barracks) {
    this->barracks = barracks;
}

void HumanBarracksUI::updateUI() {
    ui->label->setText(QString::number(barracks->unitsInQueue()));
}

void HumanBarracksUI::on_footmanButton_clicked() {
    if(!barracks || barracks->isQueueFull() || player->food == 0 || player->gold < Footman::COST_GOLD || Footman::COST_LUMBER) return;

    Footman *f = new Footman(barracks->center(),rm);
    f->useGraph(graph);
    barracks->enqueueUnit(f, 3);
    player->food--;
    player->gold -= Footman::COST_GOLD;
    player->lumber -= Footman::COST_LUMBER;

    updateUI();
}
