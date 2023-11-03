#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clock = new Clock(this);
    clock->show();

    connect(ui->start, SIGNAL(clicked()), this, SLOT(btn_start_click()));
    connect(ui->stop, SIGNAL(clicked()), this, SLOT(btn_stop_click()));
    connect(ui->reset, SIGNAL(clicked()), this, SLOT(btn_reset_click()));

    connect(clock, SIGNAL(alarm()), this, SLOT(on_alarm()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_alarm()
{
    QMessageBox msg;
    msg.setText("Время вышло!");
    msg.exec();
}
void MainWindow::btn_start_click()
{
    clock->start();
}
void MainWindow::btn_stop_click()
{
    clock->stop();
}
void MainWindow::btn_reset_click()
{
    clock->reset();
}
