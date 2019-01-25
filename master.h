#pragma once

#include <memory>
#include <vector>
#include <queue>
#include "worker.h"
#include "helpers.h"
#include "job.h"


class Master {
public:
    Master(QColor **colorTab, int size, int blocs, int workers);
    void start();
    void split();

    static Sem mutex;
    static Sem barrier;

private:
    int size;
    int blocks;
    int workers;
    QColor **colorTab;

    std::queue<std::shared_ptr<Job>> todo;
    std::vector<Worker*> workerTab;
};
