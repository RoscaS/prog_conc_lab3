#include "sem.h"


Sem::Sem(unsigned int value) { sem_init(&sem, 0, value); }

void Sem::wait() { sem_wait(&sem); }

void Sem::post() { sem_post(&sem); }

