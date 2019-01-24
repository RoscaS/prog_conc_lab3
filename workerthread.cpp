#include "workerthread.h"

bool WorkerThread::isFinish = false;

WorkerThread::WorkerThread(QColor **colorTab, int width, int height,
                           int widthStart, int heightStart, int widthEnd,
                           int heightEnd)
    : WorkerBase(), colorTab(colorTab), width(width), height(height),
      widthStart(widthStart), heightStart(heightStart), widthEnd(widthEnd),
      heightEnd(heightEnd) { }

int WorkerThread::value(int x, int y) {
    std::complex<float> point((float) x / width - 1.5,
                              (float) y / height - 0.5);
    std::complex<float> z(0, 0);
    int nb_iter = 0;
    while (abs(z) < 2 && nb_iter <= 20) {
        z = z * z + point;
        nb_iter++;
    }
    return nb_iter < 20 ? (255 * nb_iter) / 20 : 0;
}

void WorkerThread::internalThread() {
    std::cout << stringId("start");
    for (int i = widthStart; i < widthEnd; ++i) {
        for (int j = heightStart; j < heightEnd; ++j) {
            colorTab[i][j] = QColor(value(i, j), (id % 2) * 20, (id % 3) * 50);
        }
    }
    std::cout << stringId("end");
    isFinish = true;
}
