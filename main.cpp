#include <QApplication>
#include "Warcraft.hpp"
#include "Janitor.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Warcraft *game = new Warcraft();
    game->setWindowTitle("Warcraft (Kamil Kohoutek)");
    game->show();

    return a.exec();
}
