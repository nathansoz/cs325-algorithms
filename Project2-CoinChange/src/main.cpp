#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <boost/filesystem.hpp>
#include "../include/dynProgCoin.h"
#include "../include/changegreedy.h"
#include "../include/changeslow.h"
#include "../include/Helper/fileUtils.h"



#define ALGO 1 //ChangeSlow
//#define ALGO 2 //ChangeGreedy
//#define ALGO 3 //Dynamic Programming

#ifndef ALGO
#define ALGO 3
#endif

void PrintHelp()
{
    std::cout << "CoinCount 1.0; Copyright (C) 2015 Jen, Dale, Nathan" << std::endl;
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
            boostPath.parent_path() / boost::filesystem::path(boostPath.stem().append("change").append(boostPath.extension()));

    if(!boost::filesystem::exists(boostPath))
    {
        std::cout << "The file at: " << path << " could not be found." << std::endl;
        exit(1);
    }

    std::ifstream inFile;
    inFile.open(path);
    if(!inFile.is_open())
    {
        std::cout << "The file at: " << path << " could not be opened." << std::endl;
        inFile.close();
        exit(1);
    }

    //Grab the info we need from the file
    std::vector<std::vector<int>> coinLists;
    std::vector<int> coinTotals;
    Helper::processCoinFile(inFile, coinLists, coinTotals);

    //Give back the file handle to the OS
    inFile.close();

    std::ofstream outStream;
    outStream.open(boostOutPath.native_file_string());
    if(!outStream.is_open())
    {
        std::cout << "Cannot open " << boostOutPath << " for writing. Check the permissions of the directory." << std::endl;
        outStream.close();
        exit(1);
    }

#if ALGO == 1
    outStream << "Results from the brute-force Solution\n";
    for(uint i = 0; i < coinLists.size(); i++)
    {
        std::vector<int> returnCoinCount;
        int total = changeslow(coinLists.at(i), coinTotals.at(i), returnCoinCount);

        Helper::WriteResultsToFile(outStream, returnCoinCount, total);
    }
#elif ALGO == 2
    outStream << "Results from the greedy Solution\n";
    for(uint i = 0; i < coinLists.size(); i++)
    {
        std::vector<int> returnCoinCount;
        int total = greedyCoin(coinLists.at(i), coinTotals.at(i), returnCoinCount);

        Helper::WriteResultsToFile(outStream, returnCoinCount, total);
    }
#elif ALGO == 3
    outStream << "Results from the Dynamic Programming Solution\n";
    for(uint i = 0; i < coinLists.size(); i++)
    {
        std::vector<int> returnCoinCount;
        int total = dynProgCoin(coinLists.at(i), coinTotals.at(i), returnCoinCount);

        Helper::WriteResultsToFile(outStream, returnCoinCount, total);
    }
#endif
    outStream.close();



}
