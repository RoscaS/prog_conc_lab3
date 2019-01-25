#include <memory>

#include <vector>
#include "master.h"

Master::Master(QColor **colorTab, int size) : colorTab(colorTab), size(size) {

}

void Master::start() {
    std::vector<std::unique_ptr<WorkerThread>> workerTab;

    int h = 0;
    int w = 0;
    int blocs = 16;

    for (int i = 0; i < blocs; i++) {

        if (w == size) {
            h += 250;
            w = 0;
        }

        workerTab.push_back(
            std::make_unique<WorkerThread>(
                colorTab, size, size, w, h, w + 250, h + 250
            )
        );

        w += 250;
    }

    for (const auto &worker : workerTab) {
        worker->start();
    }
    for (const auto &worker : workerTab) {
        worker->join();
    }
}


