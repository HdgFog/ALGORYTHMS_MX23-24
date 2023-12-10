/// @file Listing_7_25.cpp
/// @brief Implementation of graph decomposition into strongly connected components
/// @author's Shemyakin Dmitriy Krykovich Sonya Solonitsyn Maksim


#include "iostream"
#include "vector"
#include "stack"
#include "algorithm"

using namespace std;

class Graph {
public:
    int nvertices;
    vector<vector<int>> edges;
    vector<bool> discovered;

    Graph(int n) : nvertices(n), edges(n + 1), discovered(n + 1, false) {}

    void addEdge(int from, int to) {
        edges[from].push_back(to);
    }
};

void dfs(Graph& g, int vertex, stack<int>& order) {
    g.discovered[vertex] = true;
    for (int i : g.edges[vertex]) {
        if (!g.discovered[i]) {
            dfs(g, i, order);
        }
    }
    order.push(vertex);
}

Graph transpose(const Graph& g) {
    Graph gt(g.nvertices);
    for (int i = 1; i <= g.nvertices; ++i) {
        for (int j : g.edges[i]) {
            gt.addEdge(j, i);
        }
    }
    return gt;
}

void dfs2(const Graph& g, int vertex) {
    cout << vertex << " ";
    for (int i : g.edges[vertex]) {
        if (!g.discovered[i]) {
            g.discovered[i] = true;
            dfs2(g, i);
        }
    }
}

void strongComponents(Graph& g) {
    stack<int> order;
    for (int i = 1; i <= g.nvertices; ++i) {
        if (!g.discovered[i]) {
            dfs(g, i, order);
        }
    }

    Graph gt = transpose(g);
    fill(g.discovered.begin(), g.discovered.end(), false);

    int componentsFound = 0;
    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (!g.discovered[v]) {
            componentsFound++;
            cout << "Component " << componentsFound << ": ";
            dfs2(gt, v);
            cout << endl;
        }
    }
}

int main() {
    // Example usage and test
    int nvertices = 5;
    Graph g(nvertices);

    // Adding edges (1-indexed)
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 5);

    strongComponents(g);

    return 0;
}