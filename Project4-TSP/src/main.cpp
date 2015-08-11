//
// Created by nathan on 8/9/15.
//

#include "../include/TSP_Solver.h"
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream infile;

    infile.open("/tmp/tsp.txt");

    TSP_Solver solver(infile);
    solver.SolveWithNearestNeighbor();

    infile.close();


    return 0;
}