#include "Animation.hpp"
#include <QFile>

Animation::Animation(const QPixmap *spriteSheet, const int frameWidth, const int frameHeight, QList<QList<int>> &frames, const int duration, const bool looping) {
    this->spriteSheet = spriteSheet;
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;
    this->frames = frames;
    this->looping = looping;

    animationTimer.setInterval(duration);
    connect(&animationTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

void Animation::nextFrame() {
    if(currentFrameIndex < frames.size() - 1){
        currentFrameIndex++;
    } else if (looping){
        currentFrameIndex = 0;
    } else {
        stop();
    }
}
