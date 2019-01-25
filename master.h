#pragma once

#include <memory>
#include <unistd.h>
#include <vector>
#include "workerthread.h"
#include "helpers.h"

struct Job {
    int start_w, end_w, start_h, end_h;
};

class Master {
public:
    Master(QColor **colorTab, int size, int blocs, int workers);
    void start();
    void split();

private:

    int size;
    int blocks;
    int workers;
    QColor **colorTab;
    std::vector<Job> jobs;

};

