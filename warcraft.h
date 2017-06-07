#ifndef WARCRAFT_H
#define WARCRAFT_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QRectF>
#include <QRect>
#include <QGraphicsRectItem>

class Warcraft : public QGraphicsView
{
public:
    Warcraft();

    void loadBackground();
    void loadBuildings();

    void timerEvent(QTimerEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void mouseMoveEvent(QMouseEvent *event);
    QPoint p;
    bool isPressedLeftButton = false;
    QPoint *position;

    QGraphicsRectItem *rect;
};

#endif // WARCRAFT_H
