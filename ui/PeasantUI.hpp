#ifndef PEASANTUI_HPP
#define PEASANTUI_HPP

#include <QWidget>
#include "Player.hpp"

class PeasantUI : public QWidget
{
    Q_OBJECT
public:
    explicit PeasantUI(Player *player, QWidget *parent = nullptr);
    Building::Type getSelectedType() { return selectedType; }

private:
    Building::Type selectedType;

private slots:
    void clickFarm()        { selectedType = Building::H_FARM; }
    void clickBarracks()    { selectedType = Building::H_BARRACKS; }
    void clickHall()        { selectedType = Building::H_TOWNHALL; }
    void clickStables()     { selectedType = Building::H_STABLES; }
    void clickBlacks()      { selectedType = Building::H_BLACKSMITH; }
    void clickChurch()      { selectedType = Building::H_CHURCH; }
    void clickMill()        { selectedType = Building::H_LUMBERMILL; }
};

#endif // PEASANTUI_HPP
