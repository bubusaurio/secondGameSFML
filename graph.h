#pragma once
#include <iostream>
#include <vector>

using namespace std;


struct edge{
    int input, output;
    string desicion;
};

typedef pair<int, string> Pair;

pair<int, string> p1;
pair<int, string> p2;
pair<int, string> p3;

class graph: public game{
    private:

    public:
    //Representation of the adjacency list
    vector<vector<Pair>> adjList;

    graph(vector<edge> const &edges, int n){
        //Resize the vector to hold n elements of nodes
        adjList.resize(n);

        //Add edges to the directed graph
        for(auto &edge: edges){
            int input = edge.input;
            int output = edge.output;
            string desicion = edge.desicion;

            //Insert the edge
            adjList[input].push_back(make_pair(output, desicion));
        }
    }

    void desicionMaking(graph const &graph, int);
};

#include "graph.cpp"



 
