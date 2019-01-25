#pragma once

#include <semaphore.h>

class Sem {

public:

    Sem();
    explicit Sem(int);

    void init(unsigned int);

    void wait();
    void post();

private:
    sem_t sem;
};
