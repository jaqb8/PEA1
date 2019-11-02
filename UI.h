//
// Created by kubaa on 01.11.2019.
//

#ifndef PEA1_UI_H
#define PEA1_UI_H

#include "TSP.h"
#include "BruteForce.h"
#include "BranchAndBound.h"

#include <iomanip>
#include <memory>

class UI {
public:
    UI();
    void start();

private:
    void printMenu();
    void printFileWarning();

    shared_ptr<TSP> TravellingSalesmanProblem;

    BruteForce BF;
    BranchAndBound BnB;
};


#endif //PEA1_UI_H
