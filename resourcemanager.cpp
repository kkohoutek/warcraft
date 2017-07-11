#include "resourcemanager.h"
#include <QDirIterator>

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
    qDeleteAll(sprites);
}

int ResourceManager::loadFromQrc() {
    QDirIterator it(":graphics", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        addSprite(it.fileInfo().fileName(), new QPixmap(it.fileInfo().filePath()));
    }
    return 0;
}

QPixmap* ResourceManager::getSprite(QString id) const {
    return static_cast<QPixmap*>(sprites.value(id, nullptr));
}


void ResourceManager::addSprite(QString id, QPixmap* sprite) {
    sprites.insert(id, sprite);
}


void ResourceManager::deleteSprite(QString id) {
    delete getSprite(id);
    sprites.remove(id);
}

void ResourceManager::copySprite(QString keySrc, QString keyNew, bool horizontalMirror, bool verticalMirror) {
    QPixmap* copy = new QPixmap(QPixmap::fromImage(getSprite(keySrc)->toImage().mirrored(horizontalMirror,verticalMirror)));
    sprites.insert(keyNew, copy);
}


