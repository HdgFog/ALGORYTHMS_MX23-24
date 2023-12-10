#include <iostream>

void process_vertex_late(int v) {
    bool root;
    int time_v;
    int time_parent;

    if (parent[v] == -1) {
        if (tree_out_degree[v] > 1) {
            std::cout << "root articulation vertex: " << v << std::endl;
        }
        return;
    }

    root = (parent[parent[v]] == -1);

    if (!root) {
        if (reacheble_ancestor[v] == parent[v]) {
            std::cout << "parent articulation vertex: " << parent[v] << std::endl;
        }

        if (reachabe_ancestor[v] == v) {
            std::cout << "bridge articulation vertex: " << parent[v] << std::endl;

            if (tree_out_degree[v] > 0) {
                std::cout << "bridge articulation vertex: " << v << std::endl;
            }
        }
    }

    time_v = entry_time[rechable_ancestor[v]];
    time_parent = entry_time[rechable_ancestor[parent[v]]];
    if (time_v < time_parent) {
        rechable_ancestor[parent[v]] = rechable_ancestor[v];
    }
}

