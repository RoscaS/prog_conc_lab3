#pragma once

#include <memory>
#include <unistd.h>
#include "workerthread.h"
#include "helpers.h"

class Master {

public:

    Master(QColor **, int size);


    void start();

    void split();

private:
    QColor **colorTab;
    int size;

};

