#include "sem.h"


Sem::Sem() = default;

Sem::Sem(int value) {
    init(static_cast<unsigned int>(value));
}

void Sem::init(unsigned int value) {
    sem_init(&sem, 0, value);
}

void Sem::wait() { sem_wait(&sem); }

void Sem::post() { sem_post(&sem); }


