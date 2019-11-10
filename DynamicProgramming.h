//
// Created by kubaa on 09.11.2019.
//

#ifndef PEA1_DYNAMICPROGRAMMING_H
#define PEA1_DYNAMICPROGRAMMING_H

#include "TSP.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory>
#include <cmath>
#include <limits>
#include "chrono"

using namespace std;

class DynamicProgramming {
public:
    int noOfVertices = 0;
    vector<vector<int>> matrix;
    int noOfVertices2;          // noOfVertices^2
    int** g = nullptr;          // tablica funkcji podproblemow; zawiera wyniki dla juz wyliczonych funkcji
    int** next = nullptr;       // (next) tablica do tworzenia sciezki powrotnej

    explicit DynamicProgramming(shared_ptr<TSP> TravellingSalesmanProblem);
    ~DynamicProgramming();
    int DPTSP(int startV, int set);
    int run();
    void getPath(int start, int set);
    void prepareToRun();
    string generateOutput();
    chrono::high_resolution_clock::time_point startTime;
    chrono::high_resolution_clock::time_point endTime;

protected:
    shared_ptr<TSP> TravellingSalesmanProblem;
};


#endif //PEA1_DYNAMICPROGRAMMING_H
