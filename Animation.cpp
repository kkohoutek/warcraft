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

void Animation::draw(QPainter *painter){
    painter->drawPixmap(0, 0, *spriteSheet, currentPositionX(), currentPositionY(), frameWidth, frameHeight);
}

void Animation::setCurrentFrame(int index) {
    currentFrameIndex = index;
}

void Animation::start(){
    if(!animationTimer.isActive()) {
        animationTimer.start();
    }
}

void Animation::stop(){
    animationTimer.stop();
}

int Animation::currentPositionX() const {
    return frames[currentFrameIndex][0] * frameWidth;
}

int Animation::currentPositionY() const {
    return frames[currentFrameIndex][1] * frameHeight;
}
