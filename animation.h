#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include "resourcemanager.h"


class Animation : public QObject
{
    Q_OBJECT
public:
    Animation(const QPixmap *spriteSheet, const int frameWidth, const int frameHeight, QList<QList<int>> &frames, const int duration, const bool looping);

    void draw(QPainter *painter);
    void stop();
    void start();
    void setCurrentFrame(int index);

private:
    const QPixmap       *spriteSheet;
    QList<QList<int>>   frames;        // List s souřadnicemi snímků animace
    int                 frameWidth;    // Šířka snímku
    int                 frameHeight;   // Výška snímku
    int                 currentFrameIndex = 0;
    bool                looping;

    QTimer              animationTimer;

    int currentPositionX() const;
    int currentPositionY() const;

private slots:
    void nextFrame();


};

#endif // ANIMATION_H
