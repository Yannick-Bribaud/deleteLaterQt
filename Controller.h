#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Recepteur.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void start1();
    void start2();
    void start3();

private:
    QObject *obj_ = nullptr;
    Recepteur *recepteur_ = nullptr;
};

#endif // CONTROLLER_H
