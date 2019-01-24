#pragma once

#include <iostream>
#include <pthread.h>
#include "sem.h"


class WorkerBase {

public:
    WorkerBase();
    virtual ~WorkerBase();

    bool start();
    void join();

protected:
    virtual void internalThread() = 0;
    std::string stringId(const std::string &);

    unsigned int id;
    pthread_t thread;

private:
    static void *internalThreadFunc(void *This);
    static void printCounter();

    // control
    static bool debug;

    // metrics
    static unsigned int total;
    static unsigned int current_count;
};


