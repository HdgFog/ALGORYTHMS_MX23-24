#include <iostream>
#include <vector>
using namespace std;

// Структура для представления ребра графа
struct EdgeNode {
    int y;
    EdgeNode* next;

    EdgeNode(int vertex) : y(vertex), next(nullptr) {}
};

// Структура для представления вершины графа
struct Graph {
    int nvertices;
    vector<EdgeNode*> edges;

    Graph(int vertices) : nvertices(vertices), edges(vertices + 1, nullptr) {}
};

// Инициализация графа
void initializeGraph(Graph* g, bool directed) {
    // Ваша логика инициализации графа
}

// Вставка ребра в граф
void insertEdge(Graph* g, int x, int y, bool directed) {
    EdgeNode* edge = new EdgeNode(y);
    edge->next = g->edges[x];
    g->edges[x] = edge;

    if (!directed) {
        // Если граф неориентированный, добавляем обратное ребро
        insertEdge(g, y, x, true);
    }
}

// Транспонирование графа
Graph* transpose(Graph* g) {
    Graph* gt = new Graph(g->nvertices);
    gt->nvertices = g->nvertices;

    for (int x = 1; x <= g->nvertices; x++) {
        EdgeNode* p = g->edges[x];
        while (p != nullptr) {
            insertEdge(gt, p->y, x, true);
            p = p->next;
        }
    }

    return gt;
}

// Освобождение памяти, выделенной под граф
void freeGraph(Graph* g) {
    for (int i = 1; i <= g->nvertices; i++) {
        EdgeNode* p = g->edges[i];
        while (p != nullptr) {
            EdgeNode* temp = p;
            p = p->next;
            delete temp;
        }
    }
    delete g;
}

int main() {
    // Пример использования
    int numVertices = 5;
    Graph* g = new Graph(numVertices);

    // Добавление рёбер в граф
    insertEdge(g, 1, 2, true);
    insertEdge(g, 2, 3, true);
    insertEdge(g, 2, 4, true);
    insertEdge(g, 3, 5, true);
    insertEdge(g, 4, 1, true);

    // Транспонирование графа
    Graph* gt = transpose(g);

    // Вывод транспонированного графа (для проверки)
    cout << "Транспонированный граф:\n";
    for (int i = 1; i <= gt->nvertices; i++) {
        EdgeNode* p = gt->edges[i];
        while (p != nullptr) {
            cout << i << " -> " << p->y << "\n";
            p = p->next;
        }
    }

    // Освобождение памяти
    freeGraph(g);
    freeGraph(gt);

    return 0;
}
