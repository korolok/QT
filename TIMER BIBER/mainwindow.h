#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/* Defining */
#define ORGANIZATION_NAME "QTSettings"
#define ORGANIZATION_DOMAIN "www.evileg.ru"
#define APPLICATION_NAME "QSettings Program"

#define SETTINGS_TRAY "settings/tray"


#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QSettings>
#include <QMessageBox>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent * event);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_saveButton_clicked();
    void updateTime();
};
#endif // MAINWINDOW_H
