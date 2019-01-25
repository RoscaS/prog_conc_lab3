#include <memory>

#include <vector>
#include "master.h"

Master::Master(QColor **colorTab, int size, int blocks, int workers)
    : colorTab(colorTab), size(size), blocks(blocks), workers(workers) {
    split();
    start();
}

void Master::start() {
    std::vector<std::unique_ptr<WorkerThread>> workerTab;


    for (const auto &job : jobs) {
        workerTab.push_back(
            std::make_unique<WorkerThread>(
                colorTab, size, size,
                job.start_w, job.start_h,
                job.end_w, job.end_h
            )
        );
    }

    for (const auto &worker : workerTab) {
        worker->start();
    }
    for (const auto &worker : workerTab) {
        worker->join();
    }
}

void Master::split() {
    int side = size / blocks;
    for (int i = 0; i < size; i += side) {
        for (int j = 0; j < size; j += side) {
            jobs.push_back({i, i + side, j, j + side});
        }
    }
}



