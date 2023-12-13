/// @file graph.cpp
/// @brief Structur Graph
/// @author Mansurov Sh
#define MAXV 1001
#define TREE 2
#define BACK  3
#define FORWARD 4
#define CROSS  5
#include<iostream>
#include<cstdlib>

 struct Edgenode{
    int y;
    int weight;
    Edgenode *next;
};

struct Graph{
    bool directed;
    int nvertices;
    int nedges;
    int degree[MAXV - 1];
    Edgenode *edges[MAXV];
    
};

bool discovered[MAXV];
int parent[] {1,3,4,2,2, 3};
bool processed[MAXV];
int entry_time[MAXV];
int timew;
bool finished;
int tree_out_degree[MAXV];
int reachable_ancestor[MAXV];

void insert_edge(Graph *g, int x, int y, bool directed){ 
    Edgenode *p;                    /* Временный указатель */ 
    p = new Edgenode;               /*Выделяем память для Edgenode */ 
    p -> weight = 0; 
    p -> y = y; 
    p -> next = g->edges[x]; 
    g -> edges[x] = p; 
    g -> degree[x]++; 
    if ( !directed )
        insert_edge(g, y, x, true);              /* Вставка в начало списка */     
    else
        g->nedges++;
}

void print_graph(Graph *g){              /*Вывод графа*/
    int i; 
    Edgenode *p;
    for (i = 1; i <= g->nvertices; i++){
        printf("%d: ", i); 
        p = g->edges[i]; 
        while (p != NULL){
            printf(" %d", p->y); 
            p = p->next;
        }
        printf ("\n");
    } 
}

int edge_classification(int x, int y){    /*Определение типа ребра*/
    if(parent[y] == x){
        return TREE;
    }
    if(discovered[y] && !processed[y])
        return BACK;
    if(processed[y] && (entry_time[x] < entry_time[y]))
        return FORWARD;
    if(processed[y] && (entry_time[y] < entry_time[x]))
        return CROSS;
    
    std::cout <<"Warning: self loop ("<<x<< ","<<y<<")"<<std::endl;
    return -1;
}

// void initialize_search(Graph *g) {
//     int i; 
//     timew = 0; 
//     for (i = 0; i <= g->nvertices; i++){ 
//         processed[i] = false; 
//         discovered[i] = false; 
//         parent[i]= -1;
//     }
// }

// void process_vertex_early(int v){
//     reachable_ancestor[v] = v;
// }

// void process_edge(int x, int y){ 
//     int clas;                   /* edge class */ 
//     clas = edge_classification(x, y); 
    
//     if (clas == TREE)
//         tree_out_degree[x] = tree_out_degree[x] + 1; 
//     if ((clas == BACK) && (parent[x] = y)){ 
//         if( entry_time[y] < entry_time[reachable_ancestor[x]]){
//             reachable_ancestor[x] = y;
//         }  
            
//     }
// }

void dfs(Graph *g, int v){     /*Поиск в глубину*/
    Edgenode *p; 
    int y; 
    if (finished) 
        return; 
    discovered[v] = true;  
    timew = timew + 1;
    entry_time[v] = timew;
    //process_vertex_early(v); 
    p = g->edges[v]; 
    while (p != NULL){ 
        y = p->y; 
        if ( !discovered[y]){ 
            parent[y] = v; 
            //process_edge(v,y); 
            dfs (g, y); 
        }
        else if (((!processed[y]) && (parent [v] != y)) || (g->directed)) 
            //process_edge(v, y);

        if (finished) 
            return; 
        p = p -> next;
    } 
    //process_vertex_late(v);
    timew = timew + 1;
    //exit_time[v] = time;  
    processed[v] = true;
}






int main(){
    
    Graph g;
    int i;

    /* Инициализация графа */
    g.nvertices = 8;
    
    g.directed = 0;

    /* Инициализация списка смежности */
    for (i = 1; i <= g.nvertices; i++) {
        g.edges[i] = NULL;
        g.degree[i] = 0;
    }


    /* Добавление ребер */
    insert_edge(&g, 1, 2, true);
    insert_edge(&g, 3, 1, true);
    insert_edge(&g, 2, 5, true);
    insert_edge(&g, 2, 4, true);
    insert_edge(&g, 5, 3, true);
    insert_edge(&g, 5, 4, true);
    insert_edge(&g, 6, 3, true);
    insert_edge(&g, 4, 6, true);
    
    
    dfs(&g,1);
    print_graph(&g);
    std::cout<<edge_classification(2,6);
}