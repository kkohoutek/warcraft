#ifndef WARCRAFT_H
#define WARCRAFT_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>



class Warcraft : public QGraphicsView
{
public:
    Warcraft();

    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

};

#endif // WARCRAFT_H
