#include "Controller.h"
#include <QTimer>
#include <QDebug>
#include <QThread>

Controller::Controller(QObject *parent)
    : QObject(parent), obj_(new QObject(this)), recepteur_(new Recepteur(this, obj_))
{
    obj_->setObjectName("toto");
    connect(obj_, &QObject::destroyed, [] { qDebug() << "L'objet est détruit"; });
}

void Controller::start1() {
    qDebug() << "Essai 1 : on détruit le témoin tout de suite";
    qDebug() << "";

    qDebug() << "Démarrage du récepteur";
    recepteur_->start();

    qDebug() << "Suppression du témoin";
    delete obj_;
}

void Controller::start2() {
    qDebug() << "Essai 2 : le récepteur se détruit lors du prochain cycle de la run-loop";
    recepteur_->start();    
}

void Controller::start3() {
    qDebug() << "Essai 3 : on cycle les destructions";
    connect(recepteur_, &Recepteur::destroyed, obj_, &QObject::deleteLater);    
    recepteur_->start();
}
