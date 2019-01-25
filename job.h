#pragma once

#include <iostream>
#include <memory>

class Job {

public:
    Job(int, int, int, int);
    ~Job();

    int start_w;
    int end_w;
    int start_h;
    int end_h;

private:
    static bool debug;
    static void printCounter();
    static unsigned int current_count;
};

