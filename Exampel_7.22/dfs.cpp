/// @file dfs.cpp
/// @brief Обход в глубину
/// @author Mansurov Sh.

#include "graph.hpp"
#include "edge_type.cpp"


void dfs(Graph *g, int v){     /*Поиск в глубину*/
    Edgenode *р; 
    int у; 
    if (finished) 
        return; 
    discovered[v] = true;  
    time = time + 1;
    entry_time[v] = time;
    process_vertex_early(v); 
    р = g->edges[v]; 
    while (р != NULL){ 
        у = р->y; 
        if ( !discovered[y]){ 
            parent[y] = v; 
            process_edge(v, у); 
            dfs (g, у); 
        }
        else if (((!processed[y]) && (parent [v] != y)) || (g->directed)) 
            process_edge(v, у);

        if (finished) 
            return; 
        р = p -> next;
    } 
    //process_vertex_late(v);
    time = time + 1;
    //exit_time[v] = time;  
    processed[v] = true;
}


int main(){
    Graph *g;
    g->directed = true;
    g->edges
    for(int i = 0; i < (g -> nvertices) ; i++){
        g -> degree[i] = 0;
        g -> edges[i] = NULL
    }

    insert_edge(g, 2,4,true);
    insert_edge(g, 3,5,true);
    insert_edge(g, 1,6,true);

    
}