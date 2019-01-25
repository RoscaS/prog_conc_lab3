#pragma once

#include <iostream>
#include <math.h>

class Helpers {

public:
    static unsigned int sec(int value) {
        return static_cast<unsigned int>(value * 1000000);
    }

    static bool isSquare(int value) {
        if (value == 0) {
            return false;
        }
        double root = static_cast<int>(sqrt(value));
        return (root - floor(root)) == 0;
    }

};





//255 -> 300
