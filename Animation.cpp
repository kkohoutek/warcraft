#include "Animation.hpp"

Animation::Animation(const QPixmap *spriteSheet, int frameWidth, int frameHeight, QList<QList<int>> &frames, int duration, bool looping) {
    this->spriteSheet = spriteSheet;
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;
    this->frames = frames;
    this->looping = looping;

    animationTimer.setInterval(duration);
    connect(&animationTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

void Animation::start() {
    if(!animationTimer.isActive()) animationTimer.start();
}

void Animation::stop() {
    animationTimer.stop();
}

void Animation::draw(QPainter *painter) const {
    painter->drawPixmap(0, 0, *spriteSheet, currentPositionX(), currentPositionY(), frameWidth, frameHeight);
}

int Animation::currentPositionX() const {
    return frames[currentFrameIndex][0] * frameWidth;
}

int Animation::currentPositionY() const {
    return frames[currentFrameIndex][1] * frameHeight;
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
