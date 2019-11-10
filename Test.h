//
// Created by kubaa on 05.11.2019.
//

#ifndef PEA1_TEST_H
#define PEA1_TEST_H

#include "TSP.h"
#include "Algorithm.h"
#include "DynamicProgramming.h"

#include <fstream>

class Test {
public:
    Test();
    void openFile();
    void closeFile();
    std::string getTestName(char test);
    std::string test1();
    std::string test2();
    std::string test3();
    std::string test4();
    std::string test5();

private:
    std::string exactTestTemplateOnRandomData(int noOfVertices, int range, char testNumber);
    std::shared_ptr<TSP> TravellingSalesmanProblem;
    Algorithm *algorithm;
    DynamicProgramming *DP;
    std::fstream outputFile;
};


#endif //PEA1_TEST_H
