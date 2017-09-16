#include "Janitor.hpp"
#include <QMutableListIterator>

Janitor::Janitor(Warcraft *game) : QObject(game) {
    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer.setInterval(5000);
    updateTimer.start();
}

void Janitor::update() {


}
