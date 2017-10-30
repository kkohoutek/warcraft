#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <QMap>
#include <QPixmap>

/*
 * Tato třída nám umožňuje hospodařit se znovu použitelnými objekty.
 * Instance této třídy přebírá vlastníctví všech ukazatelů, které jsou jí předány.
 */
class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    QPixmap          *getSprite(const std::string &id) const;
    void             loadSprite(const std::string &id, QPixmap *sprite);
    void             deleteSprite(const std::string &id);
    void             copySprite(const std::string &idSrc, const std::string &idNew, bool horizontalMirror = false, bool verticalMirror = false);

    int              memoryUsed();

protected:
    QMap<std::string, QPixmap *> sprites;


};

#endif // RESOURCEMANAGER_HPP
