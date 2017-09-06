#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include "resourcemanager.h"


class Animation : public QObject
{
public:
    Animation(QPixmap *spriteSheet, int frameWidth, int frameHeight, QList<QList<int>> frames, int duration, bool looping);
    Animation(QString defFilePath, ResourceManager *rm = nullptr);

    void draw(QPainter *painter);
    void stop();
    void start();
    void setCurrentFrame(int index);

    QPixmap *getSpriteSheet();

private:
    QPixmap             *spriteSheet;
    QList<QList<int>>   frames;        // list s souřadnicemi snímků animace v spriteSheetu
    int                 frameWidth;    // šířka snímku
    int                 frameHeight;   // výška snímku
    int                 currentFrameIndex = 0;
    bool                looping;

    QTimer              animationTimer;

    int currentPositionX() const;
    int currentPositionY() const;

private slots:
    void nextFrame();


};

#endif // ANIMATION_H
