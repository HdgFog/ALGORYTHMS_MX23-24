#include <iostream>
#include <vector>

#define MAXV 100000

int reachable_ancestor[MAXV + 1];
int tree_out_degree[MAXV + 1];

void process_vertex_early(int v) {
    reachable_ancestor[v] = v;
}

void dfs(int v, const std::vector<std::vector<int>>& adj) {
    process_vertex_early(v);

    for (int u : adj[v]) {
        dfs(u, adj);
        reachable_ancestor[v] = reachable_ancestor[u];
    }
}

int main() {
    std::vector<std::vector<int>> adj = {
        {2, 3},
        {4, 5},
        {6},
        {},
        {},
        {7},
        {},
        {}
    };

    dfs(1, adj);

    for (int i = 1; i <= 6; ++i) {
        std::cout << reachable_ancestor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

