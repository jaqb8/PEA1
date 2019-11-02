//
// Created by kubaa on 02.11.2019.
//

#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(shared_ptr<TSP> TravellingSalesmanProblem) : BruteForce(move(TravellingSalesmanProblem)) {}

BranchAndBound::~BranchAndBound() = default;

void BranchAndBound::prepareToRun() {
    BruteForce::prepareToRun();
    currentLowerBound = 0;
    calculateStartingLowerBound();
}

void BranchAndBound::takeCareOfNode(int currentVertex) {
    for (int i = 0; i < noOfVertices; ++i) {
        if (!visitedVertices[i]) {
            int distanceToNext = TravellingSalesmanProblem->getDistance(currentVertex, i);

            if (distanceToNext < 0) continue;

            int tempLowerBound = currentLowerBound;
            currentLowerBound -= (lowestDistancesToVertices[currentVertex][1] + lowestDistancesToVertices[i][0]) / 2;
            currentDistance += distanceToNext;

            if (currentDistance + currentLowerBound < bestDistance) enumerateSolutions(i);

            currentDistance -= distanceToNext;
            currentLowerBound = tempLowerBound;
        }
    }
}

void BranchAndBound::calculateStartingLowerBound() {
    lowestDistancesToVertices.clear();
    lowestDistancesToVertices.resize(noOfVertices);

    int temp;

    for (int i = 0; i < noOfVertices; ++i) {
        temp = TravellingSalesmanProblem->getMinimumDistanceTo(i);
        lowestDistancesToVertices[i].push_back(temp);
        currentLowerBound += temp;

        temp = TravellingSalesmanProblem->getMinimumDistanceFrom(i);
        lowestDistancesToVertices[i].push_back(temp);
        currentLowerBound += temp;
    }

    currentLowerBound /= 2;
}