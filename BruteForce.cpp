//
// Created by kubaa on 01.11.2019.
//

#include "BruteForce.h"
#include <cmath>

BruteForce::BruteForce(shared_ptr<TSP> TravellingSalesmanProblem) : Algorithm(move(TravellingSalesmanProblem)) {}

BruteForce::~BruteForce() = default;

string BruteForce::showInfoBeforeRunning() {
    noOfVertices = TravellingSalesmanProblem->getNumberOfVertices();
    if (noOfVertices < 2) throw runtime_error("Macierz wierzcholkow jest pusta lub zawiera tylko jeden wierzcholek!");

    string output;
    output += "Ilosc permutacji: ";
    output += to_string(static_cast<unsigned long>(round(tgamma(noOfVertices))));
    output += "\n";
    return output;
}

string BruteForce::run() {
    prepareToRun();
    // TODO - startTime chrono
    enumerateSolutions(startVertex);
    // TODO - endTime chrono

    return generateOutput();
}

void BruteForce::prepareToRun() {
    Algorithm::prepareToRun();
    visitedVertices.clear();
    visitedVertices.resize(noOfVertices);
}

void BruteForce::enumerateSolutions(int vertex) {
    currentRoute.push_back(vertex);
    visitedVertices[vertex] = true;

    if (currentRoute.size() < noOfVertices) takeCareOfNode(vertex);
    else takeCareOfLeaf(vertex);

    visitedVertices[vertex] = false;
    currentRoute.pop_back();
}

void BruteForce::takeCareOfNode(int currentVertex) {
    for (int i = 0; i < noOfVertices; ++i) {
        if (!visitedVertices[i]) {
            int distanceToNext = TravellingSalesmanProblem->getDistance(currentVertex, i);

            if (distanceToNext < 0) continue;

            currentDistance += distanceToNext;
            enumerateSolutions(i);
            currentDistance -= distanceToNext;
        }
    }
}

void BruteForce::takeCareOfLeaf(int currentVertex) {
    noOfChecks++;
    int distanceToNext = TravellingSalesmanProblem->getDistance(currentVertex, startVertex);

    if (distanceToNext < 0) return;

    currentDistance += distanceToNext;

    if (currentDistance < bestDistance) {
        bestDistance = currentDistance;
        bestRoute = currentRoute;
    }
    currentDistance -= distanceToNext;
}

string BruteForce::generateOutput() {
    string output;

    output += "Ilosc sprawdzonych permutacji: ";
    output += to_string(noOfChecks);
    output += "\n";

    // TODO - chrono raport

    if (bestRoute.empty()) {
        output += "Nie znaleziono zadnej trasy!\n";
    } else {
        output += "Najlepsza trasa: ";

        for (auto vertex : bestRoute) {
            output += to_string(vertex);
            output += " - ";
        }

        output += to_string(bestRoute[0]);
        output += "\n";

        output += "Dlugosc najlepszej trasy: ";
        output += to_string(bestDistance);
        output += "\n";
    }

    return output;
}