#include "animation.h"
#include <QFile>

Animation::Animation(QPixmap *spriteSheet, const int frameWidth, const int frameHeight, QList<QList<int>> &frames, const int duration, const bool looping) {
    this->spriteSheet = spriteSheet;
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;
    this->frames = frames;
    this->looping = looping;


    animationTimer.setInterval(duration);
    //animationTimer.start();
    connect(&animationTimer, &QTimer::timeout, this, &nextFrame);

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
    painter->drawPixmap(0,0,*spriteSheet,currentPositionX(),currentPositionY(),frameWidth,frameHeight);
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
    return frames.at(currentFrameIndex).at(0) * frameWidth;
}

int Animation::currentPositionY() const {
    return frames.at(currentFrameIndex).at(1) * frameHeight;
}

QPixmap *Animation::getSpriteSheet(){
    return spriteSheet;
}

