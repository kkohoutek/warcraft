#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "warcraft.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(&warcraft);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape){

        this->close();
    }
}





