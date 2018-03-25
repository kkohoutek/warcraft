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

    QPixmap          *getSprite(const QString &id) const;
    void             loadSprite(const QString &id, QPixmap *sprite);
    void             deleteSprite(const QString &id);
    void             copySprite(const QString &idSrc, const QString &idNew, bool horizontalMirror = false, bool verticalMirror = false);

    int              memoryUsed();

protected:
    QMap<QString, QPixmap *> sprites;
};

#endif // RESOURCEMANAGER_HPP
