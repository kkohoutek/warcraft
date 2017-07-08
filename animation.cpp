#include "animation.h"

Animation::Animation(QPixmap *spriteSheet, int frameWidth, int frameHeight, QList<QList<int>> frames, int duration, bool looping) {
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
    if(currentFrameIndex < frames.size()-1){
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
    animationTimer.start();
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

