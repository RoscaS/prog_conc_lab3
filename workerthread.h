#pragma once

#include <QColor>
#include <QPoint>
#include <complex>
#include "workerbase.h"

class WorkerThread : public WorkerBase {

public:
    WorkerThread(QColor **, int, int, int, int, int, int);

    int value(int x, int y);

    void internalThread() override;

    static bool isFinish;
private:
    QColor **colorTab;


    int width;
    int height;

    int widthStart;
    int widthEnd;

    int heightStart;
    int heightEnd;
};

