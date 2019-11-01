//
// Created by kubaa on 27.10.2019.
//

#ifndef PEA1_TSP_H
#define PEA1_TSP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TSP {
public:
    void loadTSP(string path);
    string printData();
    unsigned long getNumberOfVertices() const;
    int getDistance(int start, int end) const;
    int getMinimumDistanceFrom(int vertex) const;
    int getMinimumDistanceTo(int vertex) const;

private:
    vector<vector<int>> TSPData;

};


#endif //PEA1_TSP_H
