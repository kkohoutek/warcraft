#ifndef WARCRAFT_H
#define WARCRAFT_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>



class Warcraft : public QGraphicsView
{
public:
    Warcraft();

    void loadBackground();
    void loadBuildings();

    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};

#endif // WARCRAFT_H
