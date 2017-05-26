#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QPixmap>
#include <QTimer>



class Animation : public QObject
{
public:
    Animation(int subImageWidth, int subImageHeight, QList<QList<int>> *frames, int duration, bool repeat);
    ~Animation();

    int currentPositionX();
    int currentPositionY();
    int getSubImageWidth();
    int getSubImageHeight();

    QTimer *getTimer();


private:
    QList<QList<int>>   *frames;
    QTimer              *animationTimer;

    int                 subImageWidth;
    int                 subImageHeight;
    int                 currentFrameIndex = 0;

    bool                repeat;

private slots:
    void nextFrame();


};

#endif // ANIMATION_H
