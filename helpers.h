#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <iostream>

#include "semaphore.h"


class Helpers {

public:

    static int randint(int min, int max) {
        return static_cast<int>(random() % max + min);;
    }

    static void randSleep(int minSec, int maxSec) {
        usleep(sec(randint(minSec, maxSec)));
    }

    static unsigned int sec(int value) {
        return static_cast<unsigned int>(value * 100000);
    }

    static bool isSquare(int value) {
        if (value == 0) {
            return false;
        }
        double root = static_cast<int>(sqrt(value));
        return (root - floor(root)) == 0;
    }

    static void stupidActivityGenerator() {
        long counter = 0;
        long value = randint(1000, 10000)*2000000000;
        while (counter < value) {
            counter ++;
        }
        counter = 0;
    }

    static void imputCheck(int argc, char *argv[]) {
        if (argc != 3 || atoi(argv[1]) < atoi(argv[2])) {
            std::cout << "usage: P_CONC_Labo3 blocks threads\n";
            exit(1);
        }
    }

};





//255 -> 300
