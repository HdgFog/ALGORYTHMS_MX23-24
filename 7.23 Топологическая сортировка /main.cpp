#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    private:
        int V;
        vector<vector<int>> adj;
        void topologicalSortUtil(int v, vector<int> &visited, stack<int> &stack) {
            visited[v] = true;
            for (int i = 0; i < adj[v].size(); ++i)
                if (!visited[adj[v][i]])
                    topologicalSortUtil(adj[v][i], visited, stack);
            stack.push(v);
            }
    public:
        Graph(int vertices) : V(vertices), adj(vertices) {}
        void addEdge(int v, int w) {
        adj[v].push_back(w);
        }

        vector<int> topologicalSort() {
            vector<int> visited(V, false);
            stack<int> stack;

            for (int i = 0; i < V; ++i)
                if (!visited[i])
                    topologicalSortUtil(i, visited, stack);

            vector<int> result;

            while (!stack.empty()) {
                result.push_back(stack.top());
                stack.pop();
            }
            return result;
            }
};

int main() {
    Graph graph(5);
    graph.addEdge(4, 4);
    graph.addEdge(1, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 2);
    graph.addEdge(3, 2);

    vector result = graph.topologicalSort();
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    return 0;
}
