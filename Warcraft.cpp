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
#define MAX_DEAD 100

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

    scene->setBackgroundBrush(QBrush(*(rm.getSprite("MAP1"))));
    loadWorld();
    loadBuildings();
    loadUnits();

    peasantUI = new PeasantUI(player, &rm, scene, this);
    peasantUI->hide();
    scene->addWidget(peasantUI);

    hthUI = new HumanTownHallUI(player, &rm, &graph, scene, this);
    hthUI->hide();
    scene->addWidget(hthUI);

    hbUI = new HumanBarracksUI(player, &rm, &graph, scene, this);
    hbUI->hide();
    scene->addWidget(hbUI);

    startTimer(18);
}

Warcraft::~Warcraft() {
    qDeleteAll(goldmines);
    qDeleteAll(trees);
    delete rect;
    delete player;
    delete enemy;
}

void Warcraft::loadBuildings() {
    spawnBuilding(new HumanTownHall(QPointF(260,120), true, &rm, player), player);
    spawnBuilding(new HumanFarm(QPointF(70, 262), true, &rm, &(player->food)), player);
    spawnBuilding(new HumanFarm(QPointF(310, 290), true, &rm, &(player->food)), player);
    //spawnBuilding(new HumanChurch(QPointF(278, 81), true, rm), player);
    spawnBuilding(new OrcTownHall(QPointF(MAP_AREA/2-300,MAP_AREA/2-300), true, &rm), enemy);
}

void Warcraft::loadUnits(){
    for(int i = 0; i < 4; i++){
        spawnUnit(new Worker(QPointF(128+i*28,128), Unit::PEASANT, player, &rm), player);;
    }
    spawnUnit(new Footman(QPointF(1500,1500), &rm), player);

    for(int i = 0; i < 4; i++){
        spawnUnit(new Grunt(QPointF(MAP_AREA/2-420+i*40, MAP_AREA/2-286-i*40), &rm), enemy);;
    }
    enemy->getUnits().first()->attack(player->getUnits().last());
}

void Warcraft::loadWorld() {
    spawnGoldmine(new Goldmine(QPointF(64,64), &rm));
    spawnGoldmine(new Goldmine(QPointF(MAP_AREA/2-192, MAP_AREA/2-192), &rm));
    spawnGoldmine(new Goldmine(QPointF(800,522), &rm));
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

    Building *currentBuilding = peasantUI->getCurrentBuilding();
    if(currentBuilding){
        QRectF r = currentBuilding->boundingRect2();
        currentBuilding->setPos(mapToScene(p) - QPointF(r.width()/2, r.height()/2));
    }

    updatePlayer(player);
    updatePlayer(enemy);
    cleanUp();

    scene()->update();
    updateUIs();

    Q_UNUSED(event);
}

void Warcraft::mousePressEvent(QMouseEvent *event){
    auto actualPos = mapToScene(event->pos());
    auto &&selected = player->getSelectedUnits();

    if(event->button() == Qt::LeftButton){

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

        Building *currentBuilding = peasantUI->getCurrentBuilding();
        if(currentBuilding){
            if(currentBuilding->collidingItems().size() == 0){
                int result = newBuilding(player, currentBuilding, worker);
                if(result == 0) {
                    peasantUI->release();
                    setUI(nullptr);
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
            }
            return;
        }

        // Klikl hráč na budovu
        for(Building *b : player->getBuildings()){
            if(b->isSelectable() && b->boundingRect2().contains(actualPos)){
                player->selectBuilding(b);
            }
        }

    } else if (event->button() == Qt::RightButton){
        // Klikl hráč na nepřítelskou jednotku
        for(Unit *eUnit : enemy->getUnits()){
            if(eUnit->isSelectable() && eUnit->boundingRect2().contains(actualPos)){
                for(Unit *pUnit : selected){
                    pUnit->attack(eUnit);
                }
                return;
            }
        }

        //Klikl hráč na nepřátelskou budovu
        for(Building *eBuilding : enemy->getBuildings()){
            if(eBuilding->isSelectable() && eBuilding->boundingRect2().contains(actualPos)){
                for(Unit *pUnit : selected){
                    pUnit->attack(eBuilding);
                }
                return;
            }
        }

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
                        static_cast<Worker *>(u)->mine(g, player->getBuildings().last());
                    }
                }
            }
        }
    }
}

void Warcraft::mouseReleaseEvent(QMouseEvent *releaseEvent) {
    if(isPressedLeftButton && releaseEvent->button() == Qt::LeftButton){
        isPressedLeftButton = false;

        QList<Unit *> selected;
        for(Unit *unit : player->getUnits()){
            if(unit->isSelectable() && rect->rect().intersects(unit->boundingRect2())){
                selected.append(unit);
            }
        }
        player->selectUnits(selected);

        for(Unit *u : selected){
            switch(u->getType()){
            case Unit::PEASANT:
                setUI(peasantUI);
                break;
            default:
                setUI(nullptr);
            }
        }

        Building *selectedBuilding = player->getSelectedBuilding();
        if(selectedBuilding && selected.isEmpty()){
            switch(selectedBuilding->getType()){
            case Building::H_TOWNHALL:
                hthUI->setHumanTownHall(reinterpret_cast<HumanTownHall *>(selectedBuilding));
                setUI(hthUI);
                break;
            case Building::H_BARRACKS:
                hbUI->setHumanBarracks(reinterpret_cast<HumanBarracks *>(selectedBuilding));
                setUI(hbUI);
                break;
            default:
                setUI(nullptr);
            }
        }

        rect->hide();
    }
}

void Warcraft::mouseMoveEvent(QMouseEvent *event) {
    if(isPressedLeftButton && !peasantUI->getCurrentBuilding()){
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

void Warcraft::updateUIs() {
    if(currentUI == hthUI){
        hthUI->updateUI();
    } else if (currentUI == hbUI){
        hbUI->updateUI();
    }
}

void Warcraft::updatePlayer(Player *p) {
    for(Unit *unit : p->getUnits()){
        unit->update();
        if(!unit->isAlive()){
            if(unit->isHighlighted()){
                unit->setHighlighted(false);

                QMutableListIterator<Unit *> i(p->getSelectedUnits());
                while(i.hasNext()){
                    Unit *next = i.next();
                    if(next == unit){
                        i.remove();
                        break;
                    }
                }
            }
            if(!garbage.contains(unit)) {
                garbage.enqueue(unit);
            }
        }
    }

    for(Building *building : p->getBuildings()){
        building->update();
        if(!building->isAlive()){
            if(p->getSelectedBuilding() == building){
                building->setHighlighted(false);
                p->deselect();
            }

            if(!garbage.contains(building)) {
                garbage.enqueue(building);
            }
        }
    }

}

QLinkedList<Entity *> Warcraft::staticEntities() const {
    QLinkedList<Entity *> list;
    for(Building *b : player->getBuildings()){
        list.prepend(b);
    }
    for(Building *b : enemy->getBuildings()){
        list.prepend(b);
    }
    for(Goldmine *g : goldmines){
        list.prepend(g);
    }
    return list;
}

QLinkedList<Unit *> Warcraft::allUnits() const {
    QLinkedList<Unit *> allUnits;
    for(Unit *u : player->getUnits()){
        allUnits.prepend(u);
    }
    for(Unit *u : enemy->getUnits()){
        allUnits.prepend(u);
    }
    return allUnits;
}

QLinkedList<Entity *> Warcraft::allEntities() const {
    QLinkedList<Entity *> &&allEntities = staticEntities();
    for(Unit *u : allUnits()){
        allEntities.prepend(u);
    }
    return allEntities;
}

void Warcraft::spawnUnit(Unit *u, Player *owner) {
    if(owner) owner->getUnits().prepend(u);
    scene()->addItem(u);
    u->useGraph(&graph);
}

void Warcraft::spawnBuilding(Building *b, Player *owner) {
    if(owner) owner->getBuildings().prepend(b);
    scene()->addItem(b);
    graph.update(staticEntities());
}

void Warcraft::spawnGoldmine(Goldmine *g) {
    goldmines.prepend(g);
    scene()->addItem(g);
    graph.update(staticEntities());
}

void Warcraft::paintEvent(QPaintEvent *event) {
    QGraphicsView::paintEvent(event); 
    QPainter painter(viewport());
    painter.setPen(Qt::white);
    painter.drawText(QPointF(width()*3/6, 20),
        "Units: "+QString::number(player->getUnits().size())+"/100"
        "    Food: "+QString::number(player->food)+
        "    Gold: "+QString::number(player->gold)+
        "    Lumber: "+QString::number(player->lumber));

     // visualize graph

    /*
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
    rm.loadSprite("ICONS", new QPixmap(":graphics/ICONS"));
    rm.loadSprite("MAP1", new QPixmap(":graphics/MAP1"));
    rm.loadSprite("BUILDINGS_H", new QPixmap(":graphics/BUILDINGS_H"));
    rm.loadSprite("BUILDINGS_O", new QPixmap(":graphics/BUILDINGS_O"));
    rm.loadSprite("FOOTMAN", new QPixmap(":graphics/FOOTMAN"));
    rm.loadSprite("GRUNT", new QPixmap(":graphics/GRUNT"));
    rm.loadSprite("DAEMON", new QPixmap(":graphics/DAEMON"));
    rm.loadSprite("PEASANT", new QPixmap(":graphics/PEASANT"));
    rm.loadSprite("MISC", new QPixmap(":graphics/MISC"));
    rm.loadSprite("WORLD", new QPixmap(":graphics/WORLD"));
    rm.copySprite("PEASANT", "PEASANT_flipped", true, false);
    rm.copySprite("FOOTMAN", "FOOTMAN_flipped", true, false);
    rm.copySprite("GRUNT", "GRUNT_flipped", true, false);
    rm.copySprite("DAEMON", "DAEMON_flipped", true, false);
}


void Warcraft::cleanUp() {
    if(garbage.size() <= MAX_DEAD || garbage.isEmpty()) return;
    Entity *e = garbage.dequeue();
    bool removed = false;
    removed = player->getBuildings().removeOne(static_cast<Building *>(e));
    if(!removed) removed = player->getUnits().removeOne(reinterpret_cast<Unit *>(e));
    if(!removed) removed = enemy->getUnits().removeOne(reinterpret_cast<Unit *>(e));
    if(!removed) removed = enemy->getBuildings().removeOne(static_cast<Building *>(e));
    if(!removed) removed = goldmines.removeOne(reinterpret_cast<Goldmine *>(e));
    if(!removed) removed = trees.removeOne(reinterpret_cast<Trees *>(e));
    e->scene()->removeItem(e);
    delete e;
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

void Warcraft::setUI(QWidget *ui) {
    if(currentUI) currentUI->hide();
    currentUI = ui;
    if(ui) ui->show();
}

size_t Warcraft::entitiesMemoryStatus() const {
    size_t bytes = 0;
    for(Entity *e : allEntities()){
        bytes += sizeof(*e);
    }
    return bytes;
}
