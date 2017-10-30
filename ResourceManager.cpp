#include "ResourceManager.hpp"
#include <QDirIterator>

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager() {
    qDeleteAll(sprites);
}

QPixmap *ResourceManager::getSprite(const std::string &id) const {
    return sprites.value(id, nullptr);
}

void ResourceManager::loadSprite(const std::string &id, QPixmap* sprite) {
    sprites.insert(id, sprite);
}

void ResourceManager::deleteSprite(const std::string &id) {
    delete getSprite(id);
    sprites.remove(id);
}

void ResourceManager::copySprite(const std::string &idSrc, const std::string &idNew, bool horizontalMirror, bool verticalMirror) {
    QPixmap* copy = new QPixmap(QPixmap::fromImage(getSprite(idSrc)->toImage().mirrored(horizontalMirror,verticalMirror)));
    sprites.insert(idNew, copy);
}

int ResourceManager::memoryUsed() {
    return sprites.size() * sizeof(QPixmap);
}


