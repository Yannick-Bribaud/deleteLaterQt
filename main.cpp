#include <QCoreApplication>
#include <Controller.h>
#include <QDebug>

#define TP 3

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Controller c;

#if(TP == 1)
    c.start1();
#endif

#if(TP == 2)
    c.start2();
#endif

#if(TP == 3)
    c.start3();
#endif

    return a.exec();
}
