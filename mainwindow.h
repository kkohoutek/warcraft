#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWheelEvent>
#include "warcraft.h"
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static const int WIDTH = 960;
    static const int HEIGHT = 720;
    static const bool END = false;

private:
    Ui::MainWindow *ui;
    Warcraft warcraft;
    void keyPressEvent(QKeyEvent *event);


};

#endif // MAINWINDOW_H
