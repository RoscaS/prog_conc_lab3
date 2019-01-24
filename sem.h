#pragma once
#include <semaphore.h>

class Sem {

public:
    Sem(unsigned int value);
    void wait();
    void post();

private:
    sem_t sem;
};
