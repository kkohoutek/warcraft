#include "resources.h"

Resources::Resources()
{
    humanBuildings.load(":graphics/BUILDINGS_H");
    orcBuildings.load(":graphics/BUILDINGS_O");
    misc.load(":graphics/MISC");
    footman.load(":graphics/FOOTMAN");
    footmanFlipped = QPixmap::fromImage(footman.toImage().mirrored(true, false));
    peasant.load(":graphics/PEASANT");
    peasantFlipped = QPixmap::fromImage(peasant.toImage().mirrored(true, false));
    grunt.load(":graphics/GRUNT");
    gruntFlipped = QPixmap::fromImage(grunt.toImage().mirrored(true, false));
    daemon.load(":graphics/DAEMON");
    daemonFlipped = QPixmap::fromImage(daemon.toImage().mirrored(true, false));
}
