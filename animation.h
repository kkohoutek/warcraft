#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>
#include <QPixmap>
#include <QTimer>



class Animation : public QObject
{
public:
    Animation(int subImageWidth, int subImageHeight, QList<QList<int>> *frames, int duration, bool looping);
    ~Animation();

    void stop();
    void setCurrentFrame(int index);

    int currentPositionX();
    int currentPositionY();
    int getSubImageWidth();
    int getSubImageHeight();


private:
    // list s souřadnicemi snímků animace v spriteSheetu
    QList<QList<int>>   *frames;
    int                 subImageWidth;  // šířka snímku
    int                 subImageHeight; // výška snímku
    int                 currentFrameIndex = 0;
    bool                looping;

    QTimer              *animationTimer;

private slots:
    void nextFrame();


};

#endif // ANIMATION_H
