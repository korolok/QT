#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QTimer>
#include <QLCDNumber>

class Clock : public QLCDNumber
{
    Q_OBJECT

public:
    Clock(QWidget *parent = nullptr);
    void start();
    void stop();
    void reset();

private:
    int second;
    QTimer *timer;
    int period;

private slots:
    void on_timer();
signals:
    void alarm();
};

#endif // CLOCK_H
