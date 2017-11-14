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

    QPixmap          *getSprite(const char *id) const;
    void             loadSprite(const char *id, QPixmap *sprite);
    void             deleteSprite(const char *id);
    void             copySprite(const char *idSrc, const char *idNew, bool horizontalMirror = false, bool verticalMirror = false);

    int              memoryUsed();

protected:
    QMap<const char *, QPixmap *> sprites;


};

#endif // RESOURCEMANAGER_HPP
