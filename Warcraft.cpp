#include "Warcraft.hpp"

#include "entity/building/buildings_all.hpp"
#include "entity/Trees.hpp"
#include "entity/unit/Grunt.hpp"
#include "entity/unit/Footman.hpp"
#include "pathfinding.hpp"
#include "ui/PeasantUI.hpp"

#include <QScrollBar>
#include <QDebug>

#define MAP_AREA 4096

Warcraft::Warcraft() {
    setFixedHeight(600);
    setFixedWidth(800);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setMouseTracking(true);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, MAP_AREA/2, MAP_AREA/2);
    setScene(scene);
    centerOn(0, 0);

    rect = new QGraphicsRectItem();
    scene->addItem(rect);
    rect->hide();

    player = new Player(HUMAN);
    player->lumber = 100000;
    player->gold = 50000;
    enemy = new Player(ORC);

    initResources();

    scene->setBackgroundBrush(QBrush(*(rm->getSprite("MAP1"))));
    loadWorld();
    loadUnits();
    loadBuildings();

    graph.update(staticEntities());


    peasantUI = new PeasantUI(&currentBuilding, player, rm, scene, this);
    peasantUI->hide();
    scene->addWidget(peasantUI);

    startTimer(18);
}

Warcraft::~Warcraft() {
    qDeleteAll(allEntities());
    delete rect;
    delete player;
    delete enemy;
    delete rm;
}

void Warcraft::loadBuildings() {
    spawnBuilding(new HumanTownHall(QPointF(216,216), true, rm), player);;
    spawnBuilding(new HumanFarm(QPointF(70, 262), true, rm, &(player->food)), player);
    spawnBuilding(new HumanFarm(QPointF(310, 290), true, rm, &(player->food)), player);
    //spawnBuilding(new HumanChurch(QPointF(278, 81), true, rm), player);
    //spawnBuilding(new HumanBarracks(QPointF(220, 400), true, rm), player);;
    spawnBuilding(new OrcTownHall(QPointF(MAP_AREA/2-300,MAP_AREA/2-300), true, rm), enemy);
}

void Warcraft::loadUnits(){
    for(int i = 0; i < 4; i++){
        spawnUnit(new Worker(QPointF(128+i*28,128), Unit::PEASANT, &(player->gold), &(player->lumber), &graph, rm), player);;
    }
    spawnUnit(new Footman(QPointF(500,120), rm), player);

    for(int i = 0; i < 4; i++){
        spawnUnit(new Grunt(QPointF(MAP_AREA/2-420+i*40, MAP_AREA/2-286-i*40), rm), enemy);;
    }
}

void Warcraft::loadWorld() {
    spawnGoldmine(new Goldmine(QPointF(64,64), rm));
    spawnGoldmine(new Goldmine(QPointF(MAP_AREA/2-192, MAP_AREA/2-192), rm));
    spawnGoldmine(new Goldmine(QPointF(800,522), rm));
}

void Warcraft::timerEvent(QTimerEvent *event) {
    QPoint p = mapFromGlobal(QCursor::pos());
    // Pohyb kamery
    if(p.x() >=  window()->width() - 50 && p.x() <= window()->width() && p.y() >= 0 && p.y() <= window()->height() ){
        horizontalScrollBar()->setValue(horizontalScrollBar()->value()+20);
    }
    else if(p.x() <= 50 && p.x() >= 0 && p.y() <= window()->height() && p.y() >= 0){
        horizontalScrollBar()->setValue(horizontalScrollBar()->value()-20);
    }

    if(p.y() >=  window()->height() - 50 && p.y() <= window()->height() && p.x() >= 0 && p.x() <= window()->width() ){
        verticalScrollBar()->setValue(verticalScrollBar()->value()+20);
    }
    else if(p.y() <= 50 && p.y() >= 0 && p.x() <= window()->width() && p.x() >= 0){
        verticalScrollBar()->setValue(verticalScrollBar()->value()-20);
    }

    if(currentBuilding){
        currentBuilding->setPos(mapToScene(p));
    }

    player->update();
    enemy->update();

    scene()->update();

    //printGameInfo();

    Q_UNUSED(event);
}

void Warcraft::mousePressEvent(QMouseEvent *event){
    auto actualPos = mapToScene(event->pos());
    auto selected = player->getSelectedUnits();

    if(event->button() == Qt::LeftButton){

        // Klikl hráč na budovu
        for(Building *b : player->getBuildings()){
            if(b->canSelect() && b->boundingRect2().contains(actualPos)){
                player->selectBuilding(b);
                return;
            }
        }

        isPressedLeftButton = true;
        position.setX(actualPos.x());
        position.setY(actualPos.y());

        if(selected.size() == 0) {
            player->deselect();
        }

        Worker *worker = nullptr;
        for(auto *i : selected){
            if(i->getType() == Unit::PEASANT){
                worker = static_cast<Worker *>(i);
                break;
            }
        }

        if(currentBuilding){
            if(currentBuilding->collidingItems().size() == 0){
                int result = newBuilding(player, currentBuilding, worker);
                if(result == 0) {
                    peasantUI->hide();
                    graph.update(staticEntities());
                    currentBuilding = nullptr;
                } else if (result == 1) {
                    message.setText("NOT ENOUGH GOLD");
                    peasantUI->cancelOption();
                } else if (result == 2) {
                    message.setText("NOT ENOUGH LUMBER");
                    peasantUI->cancelOption();
                }
            } else {
                message.setText("CAN'T BUILD HERE");
                peasantUI->cancelOption();
                peasantUI->hide();
            }
        }

    } else if (event->button() == Qt::RightButton){
        // Nastavení cesty vybraným jednotkám
        for(int i = 0; i < selected.size(); i++){
            Unit *u = selected[i];
            u->cancel();
            u->goTo(actualPos+QPointF(i*32, 0));
        }

        // Pokud hráč klikl na goldmine a má zvoleného pracovníka, pošleme ho těžit
        for(Goldmine *g : goldmines){
            if(g->boundingRect2().contains(actualPos)){
                for(Unit *u : selected){
                    if(u->getType() == Unit::PEASANT) {
                        static_cast<Worker *>(u)->mine(g, player->getBuildings()[0]);
                    }
                }
            }
        }
    }
    //QGraphicsView::mousePressEvent(event);
}

void Warcraft::mouseReleaseEvent(QMouseEvent *releaseEvent) {
    if(isPressedLeftButton && releaseEvent->button() == Qt::LeftButton){
        isPressedLeftButton = false;

        QList<Unit *> selected;
        for(Unit *unit : player->getUnits()){
            if(unit->canSelect() && rect->rect().intersects(unit->boundingRect2())){
                selected.append(unit);
            }
        }
        player->selectUnits(selected);

        for(Unit *u : selected){
            if(u->getType() == Unit::PEASANT){
                peasantUI->show();
                break;
            } else {
                peasantUI->hide();
            }
        }
        rect->hide();
    }
}

void Warcraft::mouseMoveEvent(QMouseEvent *event) {
    if(isPressedLeftButton && !currentBuilding){
        rect->hide();
        QPointF actualPos = mapToScene(event->pos());
        rect->setPen(QPen(Qt::green));
        rect->setRect(position.x(), position.y(),actualPos.x() -position.x() , actualPos.y()-position.y());
        rect->show();
    }
    Q_UNUSED(event);
}

void Warcraft::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Escape:
        window()->close();
        break;
    }
}

int Warcraft::newBuilding(Player *player, Building *building, Worker *worker) {
    int costGold = cost(building->getType()).first;
    int costLumber = cost(building->getType()).second;

    if(costGold > player->gold) return 1;
    if(costLumber > player->lumber) return 2;
    if(!player->getUnits().contains(worker)) return 3;

    player->gold -= costGold;
    player->lumber -= costLumber;
    worker->build(building);
    spawnBuilding(building, player);
    player->deselect();

    return 0;
}

QList<Entity *> Warcraft::staticEntities() const {
    QList<Entity *> list;
    for(Building *b : player->getBuildings()){
        list.append(b);
    }
    for(Building *b : enemy->getBuildings()){
        list.append(b);
    }
    for(Goldmine *g : goldmines){
        list.append(g);
    }
    return list;
}

QList<Unit *> Warcraft::allUnits() const {
    QList<Unit *> allUnits;
    allUnits.append(player->getUnits());
    allUnits.append(enemy->getUnits());
    return allUnits;
}

QList<Entity *> Warcraft::allEntities() const {
    QList<Entity *> allEntities;
    allEntities.append(staticEntities());

    for(Unit *u : allUnits()){
        allEntities.append(u);
    }
    return allEntities;
}

QList<Entity *> Warcraft::deadEntities() const {
    QList<Entity *> dead;
    for(Entity *e : allEntities()){
        if(!e->isAlive()) {
            dead.append(e);
        }
    }
    return dead;
}

void Warcraft::spawnUnit(Unit *u, Player *owner) {
    if(owner) owner->getUnits().append(u);
    scene()->addItem(u);
    u->useGraph(&graph);
}

void Warcraft::spawnBuilding(Building *b, Player *owner) {
    if(owner) owner->getBuildings().append(b);
    scene()->addItem(b);
}

void Warcraft::spawnGoldmine(Goldmine *g) {
    goldmines.append(g);
    scene()->addItem(g);
}


void Warcraft::paintEvent(QPaintEvent *event) {
    QGraphicsView::paintEvent(event); 
    QPainter painter(viewport());
    painter.setFont(QFont("sans-serif",10));
    painter.setPen(Qt::white);
    painter.drawText(QPointF(width()*3/5, 20), "FOOD: "+QString::number(player->food)+"   GOLD: "+QString::number(player->gold)+"   LUMBER: "+QString::number(player->lumber));
    /* // visualize graph
    for(int i = 0; i < NODES_ARRAY_SIZE; i++){
        for(int j = 0; j < NODES_ARRAY_SIZE; j++){
            Node *n = graph.nodes[i][j];
            if(n){
                painter.drawEllipse(mapFromScene(n->pos), 1, 1);
            }
        }
    }
    */
    message.display(&painter, width()/2, height()/2);
}

void Warcraft::initResources() {
    rm = new ResourceManager();
    rm->loadSprite("ICONS", new QPixmap(":graphics/ICONS"));
    rm->loadSprite("MAP1", new QPixmap(":graphics/MAP1"));
    rm->loadSprite("BUILDINGS_H", new QPixmap(":graphics/BUILDINGS_H"));
    rm->loadSprite("BUILDINGS_O", new QPixmap(":graphics/BUILDINGS_O"));
    rm->loadSprite("FOOTMAN", new QPixmap(":graphics/FOOTMAN"));
    rm->loadSprite("GRUNT", new QPixmap(":graphics/GRUNT"));
    rm->loadSprite("DAEMON", new QPixmap(":graphics/DAEMON"));
    rm->loadSprite("PEASANT", new QPixmap(":graphics/PEASANT"));
    rm->loadSprite("MISC", new QPixmap(":graphics/MISC"));
    rm->loadSprite("WORLD", new QPixmap(":graphics/WORLD"));
    rm->copySprite("PEASANT", "PEASANT_flipped", true, false);
    rm->copySprite("FOOTMAN", "FOOTMAN_flipped", true, false);
    rm->copySprite("GRUNT", "GRUNT_flipped", true, false);
    rm->copySprite("DAEMON", "DAEMON_flipped", true, false);
}

void Warcraft::printGameInfo() {
    int entityCount = allEntities().size();
    qDebug() << "All entities: " + QString::number(entityCount) + " (" + QString::number(entityCount * sizeof(Entity)) + " bytes)";
    int deadCount = deadEntities().size();
    qDebug() << "Alive entities: " + QString::number(entityCount - deadCount) + " (" + QString::number((entityCount - deadCount) * sizeof(Entity)) + " bytes)";
    qDebug() << "Dead entities: " + QString::number(deadCount) + " (" + QString::number(deadCount * sizeof(Entity)) + " bytes)";

}


QPair<int, int> Warcraft::cost(Building::Type type) {
    QPair<int, int> costs;
    switch(type){
    case Building::H_BARRACKS:
        costs.first = HumanBarracks::COST_GOLD;
        costs.second = HumanBarracks::COST_LUMBER;
        break;
    case Building::H_BLACKSMITH:
        costs.first = HumanBlacksmith::COST_GOLD;
        costs.second = HumanBlacksmith::COST_LUMBER;
        break;
    case Building::H_CHURCH:
        costs.first = HumanChurch::COST_GOLD;
        costs.second = HumanChurch::COST_LUMBER;
        break;
    case Building::H_FARM:
        costs.first = HumanFarm::COST_GOLD;
        costs.second = HumanFarm::COST_LUMBER;
        break;
    case Building::H_LUMBERMILL:
        costs.first = HumanLumberMill::COST_GOLD;
        costs.second = HumanLumberMill::COST_LUMBER;
        break;
    case Building::H_STABLES:
        costs.first = HumanStables::COST_GOLD;
        costs.second = HumanStables::COST_LUMBER;
        break;
    case Building::H_TOWER:
        costs.first = HumanTower::COST_GOLD;
        costs.second = HumanTower::COST_LUMBER;
        break;
    case Building::H_TOWNHALL:
        costs.first = HumanTownHall::COST_GOLD;
        costs.second = HumanTownHall::COST_LUMBER;
        break;
    default:
        costs.first = 0;
        costs.second = 0;
    }
    return costs;
}
