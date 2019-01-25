#pragma once

#include <QColor>
#include <QPoint>
#include <complex>
#include <memory>
#include <utility>

#include "workerbase.h"
#include "job.h"


class Worker : public WorkerBase {

public:
    Worker(QColor **, std::shared_ptr<Job>, int, int);

    int value(int x, int y);
    void internalThread() override;

private:
    QColor **colorTab;
    std::shared_ptr<Job> job;

    int width;
    int height;

};
