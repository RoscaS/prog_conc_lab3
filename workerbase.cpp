#include "workerbase.h"

bool WorkerBase::debug = true;
unsigned int WorkerBase::current_count = 0;
unsigned int WorkerBase::total = 0;



WorkerBase::WorkerBase() {
    WorkerBase::total++;
    WorkerBase::current_count++;
    WorkerBase::printCounter();
    id = WorkerBase::total;
};

WorkerBase::~WorkerBase() {
    WorkerBase::current_count--;
    WorkerBase::printCounter();
}

/*------------------------------------------------------------------*\
|*					        Public Methods                          *|
\*------------------------------------------------------------------*/

bool WorkerBase::start() {
    return (pthread_create(
        &thread, nullptr, internalThreadFunc, this) == 0
    );
}

void WorkerBase::join() {
    (void) pthread_join(thread, nullptr);
}

/*------------------------------------------------------------------*\
|*					        Protected Methods                       *|
\*------------------------------------------------------------------*/

/**
* Cosmetique
* @return std::string
*/
std::string WorkerBase::stringId(const std::string &action) {
    return "T" + std::to_string(id) + " " + action + "\n";
}

/*------------------------------------------------------------------*\
|*					        Private Methods                         *|
\*------------------------------------------------------------------*/

void *WorkerBase::internalThreadFunc(void *This) {
    ((WorkerBase *) This)->internalThread();
    return nullptr;
}

void WorkerBase::printCounter() {
    if (WorkerBase::debug) {
        std::cout << "Worker count: " << WorkerBase::current_count << "\n";
    }
}
