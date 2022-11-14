//
// Created by Dominika Bobik on 11/11/22.
//

#ifndef DEPTH_FIRST_SEARCH_GRAPH_H
#define DEPTH_FIRST_SEARCH_GRAPH_H

#include <vector>

using namespace std;

// Graph implementation using adjacency list
template <typename T>
struct Data {
    T value;
    vector<T> adjecentV;
};

template <typename T>
class Graph {
private:
    vector<Data<T>> g;
public:
    Graph<T>();
    int AddEdge(T v, T u);
    int AddVertex(T v);
    int RemoveEdge(T v, T u);
    int RemoveVertex(T v);
    vector<Data<T>> GetGraph();
};

template<typename T>
Graph<T>::Graph() {
    g = {};
}

template<typename T>
int Graph<T>::AddVertex(T v) {
    for (int i = 0; i < g.size(); i++)
    {
        if (g.at(i).value == v) return -1;
    }
    vector<T> vector;
    Data<T> newItem = {v, vector};
    g.push_back(newItem);
    return 0;
}

template<typename T>
int Graph<T>::AddEdge(T v, T u) {

    int flag = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (g.at(i).value == u)
        {
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        return -1;
    }

    for (int i = 0; i < g.size(); i++)
    {
        if (g.at(i).value == v)
        {
            for (int j = 0; j < g.at(i).adjecentV.size(); j++)
            {
                if (g.at(i).adjecentV.at(j) == u) return -1;
            }
            g.at(i).adjecentV.push_back(u);
            return 0;
        }
    }
}

template<typename T>
vector<Data<T>> Graph<T>::GetGraph() {
    return g;
}

template<typename T>
int Graph<T>::RemoveEdge(T v, T u) {
    for (int i = 0; i < g.size(); i++)
    {
        if (g.at(i).value == v)
        {
            for (int j = 0; j < g.at(i).adjecentV.size(); j++)
            {
                if (g.at(i).adjecentV.at(j) == u)
                {
                    g.at(i).adjecentV.erase(j);
                    return 0;
                }
            }
            return -1;
        }
    }
}

template<typename T>
int Graph<T>::RemoveVertex(T v) {
    for (int i = 0; i < g.size(); i++)
    {
        if (g.at(i).value == v)
        {
            g.erase(i);
            return 0;
        }
    }
    return -1;
}

#endif //DEPTH_FIRST_SEARCH_GRAPH_H

