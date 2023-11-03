#include "clock.h"

Clock::Clock(QWidget *parent) : QLCDNumber(parent)
{
    second = 0;
    period = 5;
    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void Clock::start()
{
    if (!timer->isActive()) timer->start();
}
void Clock::stop()
{
    if (timer->isActive()) timer->stop();
}
void Clock::reset()
{
    second = 0;
}

void Clock::on_timer()
{
    display(++second);
    if (second >= period) {
        emit alarm();
        this->stop();
    }
}
