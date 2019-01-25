#include <QApplication>
#include <QGridLayout>

#include "master.h"
#include "displaymandel.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    int blocs = 16;
    int workers = 16;


    int size = 1000;

    QColor *colorTab[size];
    for (int i = 0; i < size; i++) {
        colorTab[i] = new QColor[size];
    }

    QTime myTimer;
    myTimer.start();

    Master m{colorTab, size};
    m.start();



    int nMilliseconds = myTimer.elapsed();
    qDebug() << "Cal in:" << nMilliseconds;

    auto *displayMander = new DisplayMandel(colorTab, 0, 0, size, size);
    displayMander->setFixedSize(size, size);
    displayMander->show();

    return app.exec();
}
