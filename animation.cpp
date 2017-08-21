#include "animation.h"
#include <QFile>

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

Animation::Animation(QString defFilePath, ResourceManager *rm) {
    QFile file(defFilePath);
    file.open(QIODevice::ReadOnly);

    while(!file.atEnd()){
        auto line = file.readLine();
        if(line.startsWith("image=")){
            QString image(line.mid(5).data());
            if(!rm) {
                //pokud nebyl předán resourcemanager, alokuj nový qpixmap
                //nezapomenout na delete!
                spriteSheet = new QPixmap(image);
            } else {
                spriteSheet = rm->getSprite(image);
            }
        } else if (line.startsWith("duration=")){
            animationTimer.setInterval(QString(line.mid(9).data()).toInt());
        } else if (line.startsWith("fwidth=")){
            frameWidth = QString(line.mid(7).data()).toInt();
        } else if (line.startsWith("fheight=")){
            frameHeight = QString(line.mid(8).data()).toInt();
        } else if (line.startsWith("loop")){
            looping = true;
        } else if (line.startsWith("frame=")){
            int x = QString(line.at(6)).toInt();
            int y = QString(line.at(8)).toInt();;
            frames.append(QList<int>() << x << y);
        }
    }
    file.close();
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

