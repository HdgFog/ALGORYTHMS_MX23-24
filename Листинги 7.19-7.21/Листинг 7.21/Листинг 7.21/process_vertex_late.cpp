#include <iostream>
#include <vector>

// Объявление глобальных переменных
std::vector<int> parent;
std::vector<int> entry_time;
std::vector<int> rechable_ancestor;
std::vector<int> tree_out_degree;

// Функция для обработки вершины 
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
        if (rechable_ancestor[v] == parent[v]) {
            std::cout << "parent articulation vertex: " << parent[v] << std::endl;
        }

        if (rechable_ancestor[v] == v) {
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

int main() {
    // Инициализация глобальных переменных
    parent = std::vector<int>(10, -1);
    entry_time = std::vector<int>(10, -1);
    rechable_ancestor = std::vector<int>(10, -1);
    tree_out_degree = std::vector<int>(10, 2);

    // Пример использования функции
    process_vertex_late(1);

    return 0;
}

