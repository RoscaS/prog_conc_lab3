#pragma once

#include <QtCore/QTime>
#include <QApplication>
#include <iostream>
#include "master.h"


class Tests {

public:

    static int test(int blocks, int workers) {

        int size = (1000/blocks) * blocks;

        Master::mutex.init(1);
        Master::barrier.init(static_cast<unsigned int>(workers));

        QColor *colorTab[size];
        for (auto &i : colorTab) {
            i = new QColor[size];
        }

        QTime myTimer;
        myTimer.start();

        Master m{ colorTab, size, blocks, workers };

        int t = myTimer.elapsed();

        for (auto &i : colorTab) {
            delete[] i;
        }
        return t;
    }

    static std::map<int, std::vector<int>> runTest() {

        int side = 4;
        int cores = 1;

        std::map<int, std::vector<int>> data;

        // 4 -> 128 blocks blocks de coté.
        for (int i = 1; i <= 3; i++) {
            std::vector<int> times;

            // 1 -> 8 coeurs.
            for (int j = 0; j <= 8; j++) {
                times.push_back(test(side, cores));
                cores++;
            }
            data.insert({side, times});
            side *=2;
        }

        return data;
    }

    static std::string serialize() {
        std::map<int, std::vector<int>> tests = Tests::runTest();
        std::string s = "";

        for (const auto &item : tests) {
            s.append("{\n\tcores: " + std::to_string(item.first * item.first ) + ",");
            s.append("\n\tvalues: [");
            for (const auto &value : item.second) {
                s.append(std::to_string(value) + ", ");
            }
            s.append("]\n}");
        }
        return s;
    }
};
