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
    void generateRandomData(unsigned long noOfVertices, int range);
    string printData();
    unsigned long getNumberOfVertices() const;
    int getDistance(int start, int end) const;
    int getMinimumDistanceFrom(int vertex) const;
    int getMinimumDistanceTo(int vertex) const;
    vector<vector<int>> getMatrix();

private:
    vector<vector<int>> TSPData;

};


#endif //PEA1_TSP_H
