#include <stdio.h>

#define MAX_VERTICES 100
#define UNCOLORED 0
#define WHITE 1
#define BLACK 2

typedef struct {
    int nvertices;
    int edges[MAX_VERTICES + 1][MAX_VERTICES + 1];
} graph;

int color[MAX_VERTICES + 1];
int bipartite;

void initialize_search(graph *g) {
    int i;
    for (i = 1; i <= g->nvertices; i++) {
        color[i] = UNCOLORED;
    }
    bipartite = 1;
}

void bfs(graph *g, int start) {
    // Implement breadth-first search here
}

int complement(int color) {
    if (color == WHITE) {
        return BLACK;
    }
    if (color == BLACK) {
        return WHITE;
    }
    return UNCOLORED;
}

void process_edge(int x, int y) {
    if (color[x] == color[y]) {
        bipartite = 0;
        printf("Warning: not bipartite, due to (%d,%d)\n", x, y);
    }
    color[y] = complement(color[x]);
}

void twocolor(graph *g) {
    int i;
    for (i = 1; i <= g->nvertices; i++) {
        color[i] = UNCOLORED;
    }
    bipartite = 1;
    initialize_search(g);
    for (i = 1; i <= g->nvertices; i++) {
        if (color[i] == UNCOLORED) {
            color[i] = WHITE;
            bfs(g, i);
        }
    }
}

int main() {
    // Example usage of the algorithm
    graph g;
    g.nvertices = 6;
    int i, j;
    for (i = 1; i <= g.nvertices; i++) {
        for (j = 1; j <= g.nvertices; j++) {
            g.edges[i][j] = 0;
        }
    }
    g.edges[1][2] = 1;
    g.edges[2][1] = 1;
    g.edges[1][3] = 1;
    g.edges[3][1] = 1;
    g.edges[2][4] = 1;
    g.edges[4][2] = 1;
    g.edges[3][5] = 1;
    g.edges[5][3] = 1;
    g.edges[4][6] = 1;
    g.edges[6][4] = 1;
    g.edges[5][6] = 1;
    g.edges[6][5] = 1;

    twocolor(&g);

    if (bipartite) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

    return 0;
}