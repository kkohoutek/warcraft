#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QMap>
#include <QPixmap>

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    int loadFromQrc();

    QPixmap*    getSprite(QString id) const;

    void        addSprite(QString id, QPixmap* sprite);

    void        deleteSprite(QString id);

    void        copySprite(QString keySrc, QString keyNew, bool horizontalMirror = false, bool verticalMirror = false);



protected:
    QMap<QString, QPixmap*> sprites;



};

#endif // RESOURCEMANAGER_H
