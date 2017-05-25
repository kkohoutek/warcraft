#include "animation.h"

// Pomocná třída pro animace objektů

Animation::Animation(int subImageWidth, int subImageHeight, QList<QList<int>> *frames, int duration, bool repeat) {
    this->subImageWidth = subImageWidth;
    this->subImageHeight = subImageHeight;
    this->frames = frames;
    this->repeat = repeat;

    animationTimer = new QTimer();
    animationTimer->setInterval(duration);

    connect(animationTimer, SIGNAL(timeout()), this, SLOT(nextFrame()));
}

void Animation::nextFrame() {
    if(currentFrameIndex < frames->size()){
        currentFrameIndex++;
    } else if (repeat){
        currentFrameIndex = 0;
    }
}

Animation::~Animation() {
    delete frames;
    delete animationTimer;
}

int Animation::currentPositionX() {
    return frames->at(currentFrameIndex).at(0) * subImageWidth;

}

int Animation::currentPositionY() {
    return frames->at(currentFrameIndex).at(1) * subImageHeight;
}

int Animation::getSubImageWidth(){
    return subImageWidth;
}

int Animation::getSubImageHeight(){
    return subImageHeight;
}


