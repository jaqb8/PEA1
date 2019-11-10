//
// Created by kubaa on 09.11.2019.
//

#include "DynamicProgramming.h"

DynamicProgramming::DynamicProgramming(shared_ptr<TSP> TravellingSalesmanProblem) : TravellingSalesmanProblem(move(TravellingSalesmanProblem)) {}

DynamicProgramming::~DynamicProgramming() {
    if (g != nullptr) {
        for (int i = 0; i < noOfVertices; i++) {
            delete [] g[i];
        }
        delete [] g;
    }

    if (next != nullptr) {
        for (int i = 0; i < noOfVertices; i++) {
            delete [] next[i];
        }
        delete [] next;
    }
}

int DynamicProgramming::run() {
    for (int i = 0; i < noOfVertices; ++i) {
        for (int j = 0; j < noOfVertices2; ++j) {
            g[i][j] = -1;
            next[i][j] = -1;
        }
    }

    int result;

    startTime = chrono::high_resolution_clock::now();

    for (int i = 0; i < noOfVertices; ++i) {
        g[i][0] = matrix [i][0];
    }

    result = DPTSP(0, noOfVertices2 - 2);

    endTime = chrono::high_resolution_clock::now();

    return result;
}

void DynamicProgramming::getPath(int start, int set) {
    if (next[start][set] == -1) return;
    int i = next[start][set];
    cout << i << " - ";
    int bitMask = noOfVertices2 - 1 - (int)pow(2,i);
    int newSubset = set & bitMask;
    getPath(i, newSubset);
}

int DynamicProgramming::DPTSP(int startV, int set) {
    int minPath = (std::numeric_limits<int>::max)(), newSubset, bitMask, buf;

    if (g[startV][set] != -1) return g[startV][set];
    else {
        for (int i = 0; i < noOfVertices; i++) {
            bitMask = noOfVertices2 - 1 - (int)pow(2, i);
            newSubset = set & bitMask;
            if (newSubset != set) {
                buf = matrix[startV][i] + DPTSP(i, newSubset);
                if (buf < minPath) {
                    minPath = buf;
                    next[startV][set] = i;
                }
            }
        }
    }

    g[startV][set] = minPath;
    return minPath;
}

void DynamicProgramming::prepareToRun() {
    matrix = TravellingSalesmanProblem->getMatrix();
    noOfVertices = TravellingSalesmanProblem->getNumberOfVertices();
    noOfVertices2 = pow(2, noOfVertices);

    g = new int*[noOfVertices];
    next = new int*[noOfVertices];

    for (int i = 0; i < noOfVertices; i++) {
        g[i] = new int[noOfVertices2];
        next[i] = new int[noOfVertices2];
    }
}

string DynamicProgramming::generateOutput() {
    string output;
    output += "Dlugosc pracy algorytmu: ";
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    output += std::to_string(duration);
    output += "µs";
    output += "\n";

    cout << "\nNajlepsza trasa: 0 - ";
    getPath(0, noOfVertices2 - 2);
    cout << "0\n";

    return output;
}


