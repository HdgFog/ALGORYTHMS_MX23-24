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