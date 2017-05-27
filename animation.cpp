#include "animation.h"

Animation::Animation(int subImageWidth, int subImageHeight, QList<QList<int>> *frames, int duration, bool looping) {
    this->subImageWidth = subImageWidth;
    this->subImageHeight = subImageHeight;
    this->frames = frames;
    this->looping = looping;

    animationTimer = new QTimer();
    animationTimer->setInterval(duration);
    animationTimer->start();

    connect(animationTimer, &QTimer::timeout, this, &nextFrame);
}

void Animation::nextFrame() {
    if(currentFrameIndex < frames->size()-1){
        currentFrameIndex++;
    } else if (looping){
        currentFrameIndex = 0;
    } else {
        stop();

    }
}

Animation::~Animation() {
    delete frames;
    delete animationTimer;
}

void Animation::setCurrentFrame(int index)
{
    currentFrameIndex = index;
}

void Animation::stop(){
    animationTimer->stop();
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

