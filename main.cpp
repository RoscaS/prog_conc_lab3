#include <QApplication>
#include <QGridLayout>
#include <memory>

#include "displaymandel.h"
#include "workerthread.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int size = 1000;

    QColor *colorTab[size];
    for (int i = 0; i < size; i++) {
        colorTab[i] = new QColor[size];
    }

    QTime myTimer;
    myTimer.start();


    std::unique_ptr<WorkerThread> worker(
        new WorkerThread{ colorTab, size, size, 0, 0, size, size }
    );

    worker->start();

    while (!WorkerThread::isFinish) {
        QThread::sleep(1);
    }

    int nMilliseconds = myTimer.elapsed();
    qDebug() << "Cal in:" << nMilliseconds;

    auto *displayMander = new DisplayMandel(colorTab, 0, 0, size, size);
    // QSize windowsSize(size, size);
    // displayMander->resize(windowsSize);
    displayMander->setFixedSize(size, size);
    displayMander->show();

    return app.exec();
}
