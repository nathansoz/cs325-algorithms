//
// Created by nathan on 8/9/15.
//

#include "../include/Helper/fileUtils.h"
#include <iostream>
#include <fstream>

#include <boost/graph/graphviz.hpp>


bool AllNodesVisited(Graph* graph)
{
    std::pair<Graph::vertex_iterator, Graph::vertex_iterator> it = boost::vertices(*graph);

    while(++it.first != it.second)
    {
        if(!((*graph)[*it.first].visited))
            return false;
        else
            continue;
    }

    return true;
}

Graph::edge_descriptor FindShortestEdge(std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator> edges, Graph* graph)
{
    int shortest_distance = INT_MAX;
    Graph::edge_descriptor retEdge = *edges.second;

    while(++edges.first != edges.second)
    {
        Graph::vertex_descriptor vtx = boost::target(*edges.first, *graph);
        if(!(*graph)[vtx].visited && (*graph)[*edges.first].distance < shortest_distance)
        {
            shortest_distance = (*graph)[*edges.first].distance;
            retEdge = *edges.first;
        }

    }


    return retEdge;
}

int main()
{
    std::ifstream infile;

    infile.open("/tmp/tsp.txt");

    std::vector<std::string>* test = Helper::readLinesFromFile(infile);
    std::cout << "All lines read" << std::endl;
    Graph* graph = Helper::createGraph(test);

    std::pair<Graph::vertex_iterator, Graph::vertex_iterator> it = boost::vertices(*graph);
    Graph::vertex_descriptor desc = *it.first;
    std::pair<Graph::out_edge_iterator, Graph::out_edge_iterator> edges;

    Graph::vertex_descriptor curVert = desc;
    int distanceTraveled = 0;
    while(!AllNodesVisited(graph))
    {
        edges = boost::out_edges(curVert, *graph);
        Graph::edge_descriptor shortestEdge = FindShortestEdge(edges, graph);
        (*graph)[curVert].visited = true;
        std::cout << "Visited " << curVert << std::endl;
        curVert = boost::target(shortestEdge, *graph);
        distanceTraveled += (*graph)[shortestEdge].distance;

    }

    std::cout << distanceTraveled << std::endl;

    infile.close();


    return 0;
}