#include <stdbool.h>
#include <stdio.h> // добавим подключение заголовочного файла для функции printf

#define MAXV 1000

#define UNCOLORED 0
#define WHITE 1
#define BLACK 2

typedef struct {
    int nvertices;
    // другие поля графа
} graph;

bool bipartite;
int color[MAXV+1];
bool discovered[MAXV+1];

// объявление функций
void initialize_search(graph *g);
void bfs(graph *g, int start);

void twocolor(graph *g) {
    int i;
    for (i = 1; i <= g->nvertices; i++) {
        color[i] = UNCOLORED;
        discovered[i] = false;
    }
    bipartite = true;
    initialize_search(g);
    for (i = 1; i <= g->nvertices; i++) {
        if (!discovered[i]) {
            color[i] = WHITE;
            bfs(g, i);
        }
    }
}

// другие функции оставляем без изменений
void process_edge(int x, int y);
int complement(int color);
int main() {
    graph g;
    g.nvertices = 6;
    // инициализация графа, добавление ребер и прочие действия...

    twocolor(&g);

    // Выводим результат раскраски
    int i;
    printf("Результат раскраски:\n");
    for (i = 1; i <= g.nvertices; i++) {
        if (color[i] == WHITE) {
            printf("Вершина %d: Белый\n", i);
        } else if (color[i] == BLACK) {
            printf("Вершина %d: Черный\n", i);
        } else {
            printf("Вершина %d: Не раскрашена\n", i);
        }
    }

    return 0;
}