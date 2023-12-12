/// @file graph.cpp
/// @brief Structur Graph
/// @author Mansurov Sh
#define MAXV 1001

typedef struct {
    int y;
    int weight;
    Edgenode *next;
}Edgenode;

typedef struct {
    bool directed;
    int nvertices;
    int nedges;
    int degree[MAXV - 1];
    Edgenode *edges[MAXV];
    
}Graph;

bool discovered[MAXV];
int parent[MAXV];
bool processed[MAXV];
int entry_time[MAXV];
int timew;
bool finished;
int tree_out_degree[MAXV];
int reachable_ancestor[MAXV];
void initialize_graph(Graph *g, bool directed){
     
    g->nvertices = 0; 
    g->nedges = 0; 
    g->directed = directed; 
    for (int i = 1; i <= MAXV; i++) 
        g->degree[i] = 0; 
    for (int i = 1; i <= MAXV; i++) 
        g->edges[i] = NULL;
}

void read_graph(Graph *g, bool directed) { 
    int i; 
    int m; 
    int x, у;  
    initialize_graph(g, directed); 
    scanf(" %d %d", &(g -> nvertices), &m); 
    for ( i = 1; i <= m; i ++ ) { 
    scanf(" %d %d", &x, &у); 
    insert_edge(g, x, у, directed); 
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

void print_graph(Graph *g){
    int i; 
    Edgenode *р;  
    for (i = l; i <= g->nvertices; i++){
        printf("%d: ", i); 
        р = g->edges[i]; 
        while (р != NULL){
            printf(" %d", р->у); 
            р = p->next;
        }
        printf ("\n");
    } 
}

void process_edge(int х, int у){ 
    int clas ;                   /* edge class */ 
    clas = edge_classification(x, y); 
    
    if (clas == TREE)
        tree_out_degree[x] = tree_out_degree[x] + 1; 
    if ((clas == BACK) && (parent[x] = у)){ 
        if( entry_time[y] < entry_time[reachable_ancestor[x]]){
            reachable_ancestor[x] = y;
        }  
            
    }
}

void process_vertex_early(int v){
    reachable_ancestor[v] = v;
}


