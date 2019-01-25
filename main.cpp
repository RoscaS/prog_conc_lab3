#include <QApplication>
#include <QGridLayout>

#include "master.h"
#include "displaymandel.h"




int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    int blocks = 4;
    int workers = 16;

    const int size = (1000 / blocks) * blocks;


    QColor *colorTab[size];

    for (auto &i : colorTab) {
        i = new QColor[size];
    }


    QTime myTimer;
    myTimer.start();

    Master m{colorTab, size, blocks, workers};


    int nMilliseconds = myTimer.elapsed();
    qDebug() << "Cal in:" << nMilliseconds;

    auto *displayMander = new DisplayMandel(colorTab, 0, 0, size, size);
    displayMander->setFixedSize(size, size);
    displayMander->show();



    for (auto &i : colorTab) {
        delete [] i;
    }

    return app.exec();
}
