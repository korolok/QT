#ifndef SUBJECT_H
#define SUBJECT_H

#include<QObject>
#include "observer.h"
class Subject : public QObject
{
    Q_OBJECT
public:
    virtual void registerObserver(Observer*);
    virtual void removeObserver(Observer*);
    virtual void notifyObserver();
};

#endif // SUBJECT_H
