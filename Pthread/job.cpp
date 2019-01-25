#include "job.h"

bool Job::debug = false;
unsigned int Job::current_count = 0;

Job::Job(int start_w, int end_w, int start_h, int end_h)
    : start_w(start_w), end_w(end_w), start_h(start_h), end_h(end_h) {
    Job::current_count++;
    Job::printCounter();
}

Job::~Job() {
    Job::current_count--;
    Job::printCounter();
}

void Job::printCounter() {
    if (Job::debug) {
        std::cout << "Jobs count: " << Job::current_count << "\n";
    }
}
