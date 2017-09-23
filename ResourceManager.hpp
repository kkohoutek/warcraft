#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <QMap>
#include <QPixmap>

/*
 * Tato třída nám umožňuje hospodařit se znovu použitelnými objekty (pixmap).
 * Instance této třídy přebírá vlastníctví všech objektů, které jsou jí předány.
 */
class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    QPixmap          *getSprite(QString id) const;
    void             loadSprite(QString id, QPixmap *sprite);
    void             deleteSprite(QString id);
    void             copySprite(QString idSrc, QString idNew, bool horizontalMirror = false, bool verticalMirror = false);

    int              memoryUsed();

protected:
    QMap<QString, QPixmap *> sprites;

};

#endif // RESOURCEMANAGER_HPP
