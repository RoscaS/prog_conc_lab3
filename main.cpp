#include <QApplication>
#include <QGridLayout>

#include "master.h"
#include "displaymandel.h"

int main(int argc, char *argv[]) {
    Helpers::imputCheck(argc, argv);

    QApplication app(argc, argv);

    auto blocks = static_cast<unsigned int>(atoi(argv[1]));
    auto workers = static_cast<unsigned int>(atoi(argv[2]));
    const int size = (1000 / blocks) * blocks;

    Master::mutex.init(1);
    Master::barrier.init(workers);

    QColor *colorTab[size];
    for (auto &i : colorTab) {
        i = new QColor[size];
    }

    QTime myTimer;
    myTimer.start();

    Master m{ colorTab, size, (int) blocks, (int) workers };

    int nMilliseconds = myTimer.elapsed();
    qDebug() << "\n\nCal in:" << nMilliseconds << "\n\n";

    auto *displayMander = new DisplayMandel(colorTab, 0, 0, size, size);
    displayMander->setFixedSize(size, size);
    displayMander->show();


    for (auto &i : colorTab) {
        delete[] i;
    }
    return app.exec();
}
