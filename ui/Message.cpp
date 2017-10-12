#include "Message.hpp"

Message::Message() {
    duration.setSingleShot(true);
    connect(&duration, SIGNAL(timeout()), this, SLOT(emptyText()));
}

void Message::display(QPainter *painter, int x, int y) const {
    if(!text.isEmpty()){
        painter->drawText(QPointF(x,y), text);
    }
}

void Message::setText(const QString &text){
    this->text = text;
    duration.stop();
    duration.start(3000);
}

void Message::emptyText() {
    text.clear();
}
