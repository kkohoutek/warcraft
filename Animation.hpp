#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include "ResourceManager.hpp"


// Tato třída reprezentuje animaci podle sprite sheetu.

class Animation : public QObject
{
    Q_OBJECT
public:
    Animation(const QPixmap *spriteSheet, const int frameWidth, const int frameHeight, QList<QList<int>> &frames, const int duration, const bool looping);

    void start()                    { if(!animationTimer.isActive()) animationTimer.start(); }
    void stop()                     { animationTimer.stop(); }
    void draw(QPainter *painter)    { painter->drawPixmap(0, 0, *spriteSheet, currentPositionX(), currentPositionY(), frameWidth, frameHeight); }
    void setCurrentFrame(int index) { currentFrameIndex = index; }

private:
    const QPixmap       *spriteSheet;
    QList<QList<int>>   frames;             // List s souřadnicemi snímků animace
    int                 frameWidth;         // Šířka snímku
    int                 frameHeight;        // Výška snímku
    int                 currentFrameIndex = 0;
    bool                looping;

    QTimer              animationTimer;

    int currentPositionX() const { return frames[currentFrameIndex][0] * frameWidth; }
    int currentPositionY() const { return frames[currentFrameIndex][1] * frameHeight; }

private slots:
    void nextFrame();
};

#endif // ANIMATION_HPP
