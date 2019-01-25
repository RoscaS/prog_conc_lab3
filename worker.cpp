
#include "worker.h"
#include "master.h"


Worker::Worker(QColor **colorTab, std::shared_ptr<Job> job, int width, int height)
    : WorkerBase(), job(std::move(job)), colorTab(colorTab), width(width), height(height) {}


int Worker::value(int x, int y) {
    std::complex<float> point(
        static_cast<float>((float) x / width - 1.5),
        static_cast<float>((float) y / height - 0.5)
    );
    std::complex<float> z(0, 0);
    int nb_iter = 0;
    while (abs(z) < 2 && nb_iter <= 20) {
        z = z * z + point;
        nb_iter++;
    }
    return nb_iter < 20 ? (255 * nb_iter) / 20 : 0;
}

void Worker::internalThread() {
    for (int i = job->start_w; i < job->end_w; ++i) {
        for (int j = job->start_h; j < job->end_h; ++j) {
            colorTab[i][j] = QColor(value(i, j), (id % 2) * 20, (id % 3) * 50);
        }
    }
    // Helpers::randSleep(1, 99);
    // Helpers::stupidActivityGenerator();
    Master::barrier.post();
    join();
    delete this;
}
