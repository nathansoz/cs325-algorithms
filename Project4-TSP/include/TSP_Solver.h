#ifndef HELLO_TSP_SOLVER_H
#define HELLO_TSP_SOLVER_H

#include <vector>
#include <fstream>

#define CITY_ID 0
#define X_COORD 1
#define Y_COORD 2


//TSP
struct TSP_City
{
    int id;
    int x;
    int y;
    bool visited;
};

class TSP_Solver
{
private:
    std::vector<TSP_City*> *cities;
    bool populated;


    int ComputeDistance(int x1, int y1, int x2, int y2);
    void PopulateCities(std::vector<std::string>*);
    int NearestNeighborFromCity(TSP_City*);
    TSP_City* FindClosestCity(TSP_City*);
    bool AllCitiesVisited();
    std::vector<std::string>* readLinesFromFile(std::istream&);
    std::vector<std::vector<int>*>* vectorizeLines(std::vector<std::string>* fileLines);
    std::vector<int>* spaceToInt(std::string &convertString);
    void ResetVisited();


public:
    //Constructors and Destructors

    TSP_Solver(std::istream&);
    ~TSP_Solver();

    void SolveWithNearestNeighbor();

};



#endif //HELLO_TSP_SOLVER_H
