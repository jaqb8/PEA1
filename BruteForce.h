//
// Created by kubaa on 01.11.2019.
//

#ifndef PEA1_BRUTEFORCE_H
#define PEA1_BRUTEFORCE_H

#include "Algorithm.h"

using namespace std;

class BruteForce : public Algorithm {
public:
    explicit BruteForce(shared_ptr<TSP> TravellingSalesmanProblem);
    ~BruteForce() override;
    string showInfoBeforeRunning() override;
    string run() override;

protected:
    void prepareToRun() override;
    virtual void enumerateSolutions(int vertex);
    virtual void takeCareOfNode(int currentVertex);
    virtual void takeCareOfLeaf(int currentVertex);
    string generateOutput() override;
    vector<bool> visitedVertices;
};


#endif //PEA1_BRUTEFORCE_H
