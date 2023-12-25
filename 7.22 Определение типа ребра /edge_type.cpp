/// @file edge_type.cpp
/// @brief Определяем тип ребра
/// @author Mansurov Sh.

#include <iostream>
#include "dfs.cpp"

#define TREE 2
#define BACK  3
#define FORWARD 4
#define CROSS  5

int edge_classification(int x, int y){    /*Определение типа ребра*/
    if(parent[y] == x)
        return TREE;
    if(discovered[y] && !processed[y])
        return BACK;
    if(processed[y] && (entry_time[x] < entry_time[y]))
        return FORWARD;
    if(processed[y] && (entry_time[y] < entry_time[x]))
        return CROSS;
    
    std::cout <<"Warning: self loop ("<<x<< ","<<y<<")"<<std::endl;
    return -1;
}


// int main(){
//     int parent[] = {2,3,5,4};
//     bool discovered[] {1,0,1,1,0};
//     bool processed[]  {1,1,0,1,0};
//     int entry_time[] {1,3,2,4,5};
//     std::cout<<edge_classification(2,5);

// }
void process_vertex_early(int v) {  /*Обработка вершины*/  
    std::cout<<" "<< v <<" ";
}


void find_path(int start, int end, int parents[]){
    if ( (start == end) || (end == -1)) { 
        std::cout <<"\n"<<start; 
    }
    else { 
        find_path(start, parents[end], parents); 
        printf(" %d", end);
    }
    
}

void process_edge(int x, int y) { 
    if (parent[y] != x ) {      /* Найдено обратное ребр 1 */ 
        std::cout << "Cycle from "<< y <<" to "<<x; 
        find_path(y, x, parent); 
        finished = true;
    }
}

// void process_edge(int х, int у){ 
//     int clas ;                   /* edge class */ 
//     clas = edge_classification(x, y); 
    
//     if (clas == TREE)
//         tree_out_degree[x] = tree_out_degree[x] + 1; 
//     if ((clas == BACK) && (parent[x] = у)){ 
//         if( entry_time[y] < entry_time[reachable_ancestor[x]]){
//             reachable_ancestor[x] = y;
//         }  
            
//     }
// }

void initialize_search(Graph *g) {
    int i; /* Счетчик */ 
    time = 0; 
    for (i = 0; i <= g->nvertices; i++){ 
        processed[i] = false; 
        discovered[i] = false; 
        parent[i]= -1;
    }
}

void insert_edge(Graph *g, int x, int y, bool directed){ 
    Edgenode *р;                    /* Временный указатель */ 
    р = malloc(sizeof(Edgenode));   /*Выделяем память для Edgenode */ 
    p -> weight = 0; 
    р -> y = y; 
    p -> next = g->edges[x]; 
    g -> edges[x] = р; 
    g -> degree[x]++; 
    if ( !directed )
        insert_edge(g, y, x, true);              /* Вставка в начало списка */     
    else
        g->nedges++;
}