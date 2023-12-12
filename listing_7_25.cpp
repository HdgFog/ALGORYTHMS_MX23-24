/// @file Listing_7_25.cpp
/// @brief Implementation of graph decomposition into strongly connected components
/// @author's Shemyakin Dmitriy Krykovich Sonya Solonitsyn Maksim


#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;

class Graph {
    int V; // Количество вершин
    list<int> *adj; // Список смежности

public:
    Graph(int V);
    void addEdge(int v, int w);
    void fillOrder(int v, vector<bool>& visited, stack<int>& stack);
    void DFSUtil(int v, vector<bool>& visited);
    void printSCCs();
    Graph getTranspose();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, vector<bool>& visited, stack<int>& stack) {
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            fillOrder(*i, visited, stack);

    stack.push(v);
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose() {
    Graph g(V);
    for (int v = 0; v < V; v++) {
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::printSCCs() {
    stack<int> stack;

    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            fillOrder(i, visited, stack);

    Graph transposed = getTranspose();

    fill(visited.begin(), visited.end(), false);

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!visited[v]) {
            transposed.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    cout << "Strongly Connected Components:\n";
    g.printSCCs();

    return 0;
}