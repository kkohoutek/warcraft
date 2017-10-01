#include "PeasantUI.hpp"

#include <QPushButton>
#include <QLayout>
#include <QGraphicsScene>

#include "entity/building/buildings_all.hpp"

PeasantUI::PeasantUI(Building **buildingPtr, Player *player, ResourceManager *rm, QGraphicsScene *scene, QWidget *parent) : QWidget(parent) {
    this->buildingPtr = buildingPtr;
    this->player = player;
    this->rm = rm;
    this->scene = scene;
    this->setGeometry(700,300,80,300);
    QGridLayout *layout = new QGridLayout(this);
    this->setLayout(layout);

    QPushButton *farm = new QPushButton("Farm", this);
    farm->setToolTip("Farms provide food for your units. Each Farm allows for four new units to be created.");
    QPushButton *hall = new QPushButton("Town Hall", this);
    hall->setToolTip("Town Halls are the center of your city; harvested lumber and mined gold is sent here to be collected and used.\nOther than that, this building trains Peasants.");
    QPushButton *barracks = new QPushButton("Barracks", this);
    barracks->setToolTip("Barracks are used to train most of your troops, Footmen, Knights, Archers and Catapults are trained here.\nBuild one and more as soon as resources allow it; the more, the merrier.\nThe bulk of your army will come out of this building, so protect it when under attack.");
    QPushButton *mill = new QPushButton("Lumber Mill", this);
    mill->setToolTip("This is where the raw wood supplied by peasant harvesters is made into building supplies.");
    QPushButton *church = new QPushButton("Church", this);
    church->setToolTip("Churches are used to train Clerics");
    QPushButton *blacks = new QPushButton("Blacksmith", this);
    blacks->setToolTip("Blacksmiths are used to upgrade the attack and armor of your melee units.");
    QPushButton *stables = new QPushButton("Stables", this);
    stables->setToolTip("Stables allow you to train Knights from a Barracks");

    this->layout()->addWidget(farm);
    this->layout()->addWidget(hall);
    this->layout()->addWidget(barracks);
    this->layout()->addWidget(mill);
    this->layout()->addWidget(church);
    this->layout()->addWidget(blacks);
    this->layout()->addWidget(stables);

    connect(farm, SIGNAL(clicked(bool)), SLOT(clickFarm()));
    connect(hall, SIGNAL(clicked(bool)), SLOT(clickHall()));
    connect(barracks, SIGNAL(clicked(bool)), SLOT(clickBarracks()));
    connect(mill, SIGNAL(clicked(bool)), SLOT(clickMill()));
    connect(church, SIGNAL(clicked(bool)), SLOT(clickChurch()));
    connect(blacks, SIGNAL(clicked(bool)), SLOT(clickBlacks()));
    connect(stables, SIGNAL(clicked(bool)), SLOT(clickStables()));

}

void PeasantUI::prepareForBuilding(Building *b) {
    // Pokud už je nějaká možnost zvolena, zruší se
    if(*buildingPtr){
        scene->removeItem(*buildingPtr);
        delete *buildingPtr;
        *buildingPtr = nullptr;
        return;
    }
    *buildingPtr = b;
    scene->addItem(b);
    b->setHighlighted(true);
}

void PeasantUI::clickFarm() {
    prepareForBuilding(new HumanFarm(QPointF(0,0),false,rm,&(player->food)));
}

void PeasantUI::clickBarracks() {
    prepareForBuilding(new HumanBarracks(QPointF(0,0),false,rm));
}

void PeasantUI::clickHall() {
    prepareForBuilding(new HumanTownHall(QPointF(0,0),false,rm));
}

void PeasantUI::clickStables() {
    prepareForBuilding((new HumanStables(QPointF(0,0),false,rm)));
}

void PeasantUI::clickBlacks() {
    prepareForBuilding(new HumanBlacksmith(QPointF(0,0),false,rm));
}

void PeasantUI::clickChurch() {
    prepareForBuilding(new HumanChurch(QPointF(0,0),false,rm));
}

void PeasantUI::clickMill() {
    prepareForBuilding(new HumanLumberMill(QPointF(0,0),false,rm));
}
