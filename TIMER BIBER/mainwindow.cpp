#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTime"
#include "QTimer"
#include "QStyle"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tray Program");
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    ui->trayCheckBox->setChecked(settings.value(SETTINGS_TRAY, false).toBool());
    QTimer *timer = new QTimer(this);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("Tray Program" "\n" "Работа со сворачиванием программы в трей");

    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(("Развернуть окно"), this);
    QAction * quitAction = new QAction(("Выход"), this);

    /* CONNECT */
    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    /* MENU */
    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    trayIcon->setContextMenu(menu);
    trayIcon->show();

    /* CONNECT SIGNAL */
    connect(trayIcon, SIGNAL(activated(QsystemTrayIcdon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    timer->start(1000);
    updateTime();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveButton_clicked()
    {
    QMessageBox msg;
    float number = ui->Name->text().toFloat();
    if (ui->Name->text().length() == 0) {
        msg.setText("Введите Имя");
        msg.exec();
    return;
    }
        QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
        /* Сохранение информации о включённости функции сворачивания
         * в трей производится в соответствии с состоянием чекбокса.
         * */
        if(ui->trayCheckBox->isChecked()){
            settings.setValue(SETTINGS_TRAY, true);
        } else {
            settings.setValue(SETTINGS_TRAY, false);
        }
        settings.setValue("settings/SETTINGS_CHACHA", ui->Name->text());
        settings.sync();

        /* Диалоговое сообщение, которое сигнализирует об успешности
         * сохранения настроек
         * */
        QMessageBox::information(this,
                                 ("Сохранение настроек"),
                                 ("Сохранение настроек выполнено успешно"));
    }
void MainWindow::closeEvent(QCloseEvent * event)
{
    if(this->isVisible() && ui->trayCheckBox->isChecked()){
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Tray Program", ("Приложение свернуто в трей. Для того чтобы, развернуть окно приложения, щелкните по иконке приложения в трее"), icon, 2000);
    }
}

/* Нажатие */
void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
        if(ui->trayCheckBox->isChecked()){
            if(!this->isVisible()){
                this->show();
            } else {
                this->hide();
            }
        }
        break;
    default:
        break;
    }
}
void MainWindow::updateTime()
{
    QTime time = QTime::currentTime();
    QString currentTime = time.toString("hh:mm:ss");
    ui->lcdNumber->display(currentTime);
}
