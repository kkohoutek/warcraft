#include "animation.h"

Animation::Animation(QPixmap *spriteSheet, int subImageWidth, int subImageHeight, QList<QList<int>> *frames, int duration, bool looping) {
    this->spriteSheet = spriteSheet;
    this->subImageWidth = subImageWidth;
    this->subImageHeight = subImageHeight;
    this->frames = frames;
    this->looping = looping;

    animationTimer = new QTimer();
    animationTimer->setInterval(duration);
    animationTimer->start();

    connect(animationTimer, &QTimer::timeout, this, &nextFrame);
}

Animation::~Animation() {
    delete frames;
    delete animationTimer;
    delete spriteSheet;
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

void Animation::draw(QPainter *painter){
    painter->drawPixmap(0,0,*spriteSheet,currentPositionX(),currentPositionY(),subImageWidth,subImageHeight);
}

void Animation::setCurrentFrame(int index) {
    currentFrameIndex = index;
}

void Animation::start(){
    animationTimer->start();
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

