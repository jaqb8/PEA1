//
// Created by kubaa on 01.11.2019.
//

#ifndef PEA1_UI_H
#define PEA1_UI_H

#include "TSP.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
#include "Test.h"

#include <iomanip>
#include <memory>

class UI {
public:
    UI();
    void start();

private:
    void printMenu();
    void printTestMenu();
    void runTestMenu();

    shared_ptr<TSP> TravellingSalesmanProblem;

    BruteForce BF;
    BranchAndBound BnB;

    Test test;
};


#endif //PEA1_UI_H
