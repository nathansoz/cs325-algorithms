//
// Created by nathan on 8/9/15.
//

#include "../include/TSP_Solver.h"
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>

void PrintHelp()
{
    std::cout << "Traveling Salesman Approx. 1.0; Copyright (C) 2015 Jen, Dale, Nathan" << std::endl;
    std::cout << "Usage: CoinCount [file]" << std::endl;
    std::cout << "-h --help    display this help" << std::endl;
}

int main(int argc, char* argv[])
{

    std::string path;

    if(argc != 2)
    {
        std::cout << "Error! This program takes exactly 1 argument. Printing usage:" << std::endl << std::endl;
        PrintHelp();
        exit(1);
    }
    else
    {
        if(std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
        {
            PrintHelp();
            exit(0);
        }
        else
            path = std::string(argv[1]);
    }

    boost::filesystem::path boostPath(path);

    boost::filesystem::path boostOutPath =
            boostPath.parent_path() / boost::filesystem::path(boostPath.stem().append(boostPath.extension()).append(".tour"));

    if(!boost::filesystem::exists(boostPath))
    {
        std::cout << "The file at: " << path << " could not be found." << std::endl;
        exit(1);
    }

    std::ifstream infile;
    infile.open(path);

    if(!infile.is_open())
    {
        std::cout << "The file at: " << path << " could not be opened." << std::endl;
        infile.close();
        exit(1);
    }

    TSP_Solver solver(infile);
    infile.close();

    std::ofstream outStream;
    outStream.open(boostOutPath.native_file_string());
    if(!outStream.is_open())
    {
        std::cout << "Cannot open " << boostOutPath << " for writing. Check the permissions of the directory." << std::endl;
        outStream.close();
        exit(1);
    }

    solver.SolveWithNearestNeighbor();
    solver.PrintBestTour(outStream);
    outStream.close();

    std::cout << "Wrote solution and tour to file " << boostOutPath << std::endl;

    return 0;
}