#include <iostream>
#include "Graph.h"

void PrintGraph(Graph<int> g)
{
    vector<Data<int>> graph = g.GetGraph();
    for (int i = 0; i < graph.size(); i++) {
        cout << graph.at(i).value << ": ";
        for (int k = 0; k < graph.at(i).adjecentV.size(); k++)
        {
            cout << graph.at(i).adjecentV.at(k) << " ";
        }
        cout << "\n";
    }
}

void PrintGraphChar(Graph<char> g)
{
    vector<Data<char>> graph = g.GetGraph();
    for (int i = 0; i < graph.size(); i++) {
        cout << graph.at(i).value << ": ";
        for (int k = 0; k < graph.at(i).adjecentV.size(); k++)
        {
            cout << graph.at(i).adjecentV.at(k) << " ";
        }
        cout << "\n";
    }
}

int main() {
    std::cout << "Graph of ints" << std::endl;
    Graph<int> g{};
    g.AddVertex(1);
    g.AddVertex(2);
    g.AddVertex(3);
    g.AddVertex(4);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(1, 1);
    g.AddEdge(4, 3);
    PrintGraph(g);
    std::cout << "Graph of chars" << std::endl;
    Graph<char> g1{};
    g1.AddVertex('A');
    g1.AddVertex('B');
    g1.AddVertex('D');
    g1.AddVertex('C');
    g1.AddEdge('A', 'R');
    g1.AddEdge('C', 'D');
    g1.AddEdge('G', 'A');
    g1.AddEdge('B', 'C');
    PrintGraphChar(g1);

    return 0;
}
