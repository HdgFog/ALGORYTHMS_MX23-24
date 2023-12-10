#include <iostream>
#include <vector>

// Константа, ограничивающая количество вершин в графе
#define MAXV 100000

// Массив, хранящий информацию о достижимых предках для каждой вершины
int reachable_ancestor[MAXV + 1];

// Массив, хранящий информацию о количестве ребер, исходящих из каждой вершины
int tree_out_degree[MAXV + 1];

// Функция, выполняющая ранний процесс вершины
void process_vertex_early(int v) {
    // Устанавливаем достижимым предком для вершины v саму вершину v
    reachable_ancestor[v] = v;
}

// Рекурсивная функция, выполняющая обход графа в глубину
void dfs(int v, const std::vector<std::vector<int>>& adj) {
    // Выполняем ранний процесс вершины
    process_vertex_early(v);

    // Для каждой вершины u, соединенной ребром с вершиной v
    for (int u : adj[v]) {
        // Рекурсивно вызываем функцию dfs для вершины u
        dfs(u, adj);

        // Устанавливаем достижимым предком для вершины v достижимый предок для вершины u
        reachable_ancestor[v] = reachable_ancestor[u];
    }
}

int main() {
    // Считываем количество вершин n и количество ребер m
    int n, m;
    std::cin >> n >> m;

    // Создаем список смежности для хранения графа
    std::vector<std::vector<int>> adj(n + 1);

    // Считываем ребра графа,соедененые верщинами, и добавляем их в список смежности
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        ++tree_out_degree[u];
    }

    // Вызываем функцию dfs для начальной вершины 1
    dfs(1, adj);

    // Выводим массив reachable_ancestor, содержащий информацию о достижимых предках для каждой вершины графа
    for (int i = 1; i <= n; ++i) {
        std::cout << reachable_ancestor[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

