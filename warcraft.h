#ifndef WARCRAFT_H
#define WARCRAFT_H

#include <QGraphicsView>
#include <QMouseEvent>



class Warcraft : public QGraphicsView
{
public:
    Warcraft();

    void timerEvent(QTimerEvent *event);

};

#endif // WARCRAFT_H
