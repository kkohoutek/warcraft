#include "resourcemanager.h"
#include <QDirIterator>

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
    qDeleteAll(sprites);
}

QPixmap *ResourceManager::getSprite(QString id) const {
    return sprites.value(id, nullptr);
}


void ResourceManager::loadSprite(QString id, QPixmap* sprite) {
    sprites.insert(id, sprite);
}

void ResourceManager::deleteSprite(QString id) {
    delete getSprite(id);
    sprites.remove(id);
}

void ResourceManager::copySprite(QString idSrc, QString idNew, bool horizontalMirror, bool verticalMirror) {
    QPixmap* copy = new QPixmap(QPixmap::fromImage(getSprite(idSrc)->toImage().mirrored(horizontalMirror,verticalMirror)));
    sprites.insert(idNew, copy);
}


