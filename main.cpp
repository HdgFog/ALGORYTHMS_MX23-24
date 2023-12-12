#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;

// Структура для представления графа
struct Graph {
    int V; // Количество вершин
    unordered_map<int, vector<pair<int, int>>> adjList; // Список смежности

    // Конструктор
    Graph(int vertices) : V(vertices) {}

    // Добавление ребра в граф
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
    }

    // Алгоритм поиска кратчайшего пути методом первый лучший
    void bestFirstSearch(int source, int target) {
        // Приоритетная очередь для выбора следующей вершины
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Массив для отслеживания посещенных вершин
        vector<bool> visited(V, false);

        // Массив для отслеживания предшественников вершин
        unordered_map<int, int> parent;

        // Начальная вершина добавляется в очередь
        pq.push(make_pair(0, source));
        parent[source] = -1;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Если найден целевой узел
            if (u == target) {
                cout << "Кратчайший путь до вершины " << target << " найден." << endl;
                cout << "Путь: ";
                printPath(parent, target);
                return;
            }

            // Помечаем вершину как посещенную
            visited[u] = true;

            // Обходим смежные вершины
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!visited[v]) {
                    pq.push(make_pair(weight, v));
                    parent[v] = u;
                }
            }
        }

        cout << "Кратчайший путь до вершины " << target << " не найден." << endl;
    }

    // Вспомогательная функция для вывода пути
    void printPath(unordered_map<int, int>& parent, int target) {
        stack<int> path;
        int current = target;
        while (current != -1) {
            path.push(current);
            current = parent[current];
        }

        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
};

int main() {
    // Создание графа с 6 вершинами
    Graph g(6);

    // Добавление ребер в граф
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 9);
    g.addEdge(2, 5, 12);
    g.addEdge(3, 4, 2);

    int source = 0; // Начальная вершина
    int target = 4; // Целевая вершина

    // Вызов алгоритма поиска кратчайшего пути
    g.bestFirstSearch(source, target);

    return 0;
}
