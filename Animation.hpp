#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QPainter>

// Tato třída reprezentuje animaci podle sprite sheetu.

class Animation : public QObject
{
    Q_OBJECT
public:
    Animation(const QPixmap *spriteSheet, int frameWidth, int frameHeight, QList<QList<int>> &frames, int duration, bool looping);

    void start();
    void stop();
    void draw(QPainter *painter);
    void setCurrentFrame(int index) { currentFrameIndex = index; }

private:
    const QPixmap       *spriteSheet;
    QList<QList<int>>   frames;             // List s souřadnicemi snímků animace
    int                 frameWidth;         // Šířka snímku
    int                 frameHeight;        // Výška snímku
    int                 currentFrameIndex = 0;
    bool                looping;

    QTimer              animationTimer;

    int currentPositionX() const;
    int currentPositionY() const;

private slots:
    void nextFrame();
};

#endif // ANIMATION_HPP
