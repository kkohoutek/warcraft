#include <QApplication>
#include "Warcraft.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Gentium Book Basic");
    a.setFont(font);

    Warcraft *game = new Warcraft();
    game->setWindowTitle("Warcraft (Kamil Kohoutek)");
    game->show();

    return a.exec();
}
