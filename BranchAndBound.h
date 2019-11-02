//
// Created by kubaa on 02.11.2019.
//

#ifndef PEA1_BRANCHANDBOUND_H
#define PEA1_BRANCHANDBOUND_H

#include "BruteForce.h"

using namespace std;

class BranchAndBound : public BruteForce {
public:
    explicit BranchAndBound(shared_ptr<TSP> TravellingSalesmanProblem);
    ~BranchAndBound() override;

private:
    void prepareToRun() override;
    void takeCareOfNode(int currentVertex) override;
    void calculateStartingLowerBound();
    int currentLowerBound;
    vector<vector<int>> lowestDistancesToVertices;
};


#endif //PEA1_BRANCHANDBOUND_H
