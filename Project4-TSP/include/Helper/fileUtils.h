#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <boost/graph/adjacency_list.hpp>

struct VertexInfo
{
    bool visited;
    int x;
    int y;
};

struct EdgeInfo
{
    int distance;
};

typedef boost::property<boost::edge_weight_t, int> EdgeWeightProp;
typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, VertexInfo, EdgeInfo> Graph;

namespace Helper
{


    std::vector<std::string>* readLinesFromFile(std::ifstream&);
    std::vector<int>* spaceToInt(std::string&);
    std::vector<std::vector<int>*>* vectorizeLines(std::vector<std::string>*);
    Graph* createGraph(std::vector<std::string>*);
}