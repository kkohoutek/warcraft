#include "ResourceManager.hpp"
#include <QDirIterator>

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
    qDeleteAll(sprites);
}

QPixmap *ResourceManager::getSprite(const char *id) const {
    return sprites.value(id, nullptr);
}

void ResourceManager::loadSprite(const char *id, QPixmap* sprite) {
    sprites.insert(id, sprite);
}

void ResourceManager::deleteSprite(const char *id) {
    delete getSprite(id);
    sprites.remove(id);
}

void ResourceManager::copySprite(const char *idSrc, const char *idNew, bool horizontalMirror, bool verticalMirror) {
    QPixmap* copy = new QPixmap(QPixmap::fromImage(getSprite(idSrc)->toImage().mirrored(horizontalMirror,verticalMirror)));
    sprites.insert(idNew, copy);
}

int ResourceManager::memoryUsed() {
    return sprites.size() * sizeof(QPixmap);
}


