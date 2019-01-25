#include <memory>

#include <vector>
#include "master.h"

Sem Master::mutex{};
Sem Master::barrier{};

Master::Master(QColor **colorTab, int size, int blocks, int workers)
    : colorTab(colorTab), size(size), blocks(blocks), workers(workers) {
    split();
    start();
}

void Master::start() {

    while (!jobs.empty()) {

        Master::barrier.wait();
        Master::mutex.wait();

        auto worker = new Worker{ colorTab, jobs.front(), size, size};
        workerTab.push_back(worker);
        jobs.pop();
        worker->start();

        Master::mutex.post();
    }
}

void Master::split() {
    int side = size / blocks;

    for (int i = 0; i < size; i += side) {
        for (int j = 0; j < size; j += side) {
            jobs.push(std::make_shared<Job>(i, i + side, j, j + side));
        }
    }
}

