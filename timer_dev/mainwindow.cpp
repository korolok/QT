#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    second = 0;
    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
  timer->start();
}

void MainWindow::on_timer()
{
    ui->lcdNumber->display(second);
    if(ui->checkBox->checkState() == 2)
    {second--;}
    else{second++;}
}

