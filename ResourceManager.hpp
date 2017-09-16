#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <QMap>
#include <QPixmap>

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    QPixmap          *getSprite(QString id) const;
    void             loadSprite(QString id, QPixmap* sprite);
    void             deleteSprite(QString id);
    void             copySprite(QString idSrc, QString idNew, bool horizontalMirror = false, bool verticalMirror = false);

protected:
    QMap<QString, QPixmap *> sprites;



};

#endif // RESOURCEMANAGER_HPP
