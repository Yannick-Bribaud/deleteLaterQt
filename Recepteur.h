#ifndef RECEPTEUR_H
#define RECEPTEUR_H

#include <QObject>

class Recepteur : public QObject
{
    Q_OBJECT
public:
    explicit Recepteur(QObject *parent = nullptr, QObject *obj = 0);
    ~Recepteur();

signals:

public slots:
    void start();

private slots:
    void onTimer();

private:
    QObject *obj_ = 0;
};

#endif // RECEPTEUR_H
