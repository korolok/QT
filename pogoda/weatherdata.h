#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include<QObject>
#include "observer.h"
#include <QTimer>
#include <ctime>
#include <iostream>


class WeatherData : public Subject
{
private:
    QList<Observer*> observers;
    float temperature;
    float humidity;
    float presure;
    QTimer *timer;
public:
    WeatherData();
    void registerObserver(Observer*);
    void removeObserver(Observer*);
    void notifyObserver();
    void measurmentsChanged();
    void setMeasurments(float,float,float);
private slots:
    void on_timer();
};
#endif // WEATHERDATA_H
