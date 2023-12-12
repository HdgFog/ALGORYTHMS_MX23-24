#include <iostream> 
#include <vector> 
using namespace std; 
 
 
struct graph { 
    int n_ver;   // число вершин 
    vector<vector<int>> adj_list;  
}; 
 
void initialize_search(graph* g, vector<bool>& discovered) { 
    int n = g->n_ver; 
    discovered.resize(n + 1, false); 
} 
 
void bfs(graph* g, int start, vector<bool>& discovered) { 
    vector<int> component;  
    component.push_back(start);  
    discovered[start] = true;  
 
    int front = 0; // указатель на начало очереди 
    while (front < component.size()) { 
        int current_ver = component[front]; 
        cout << current_ver << " "; 
 
        for (int i = 0; i < g->adj_list[current_ver].size(); i++) { 
            int adjacent_ver = g->adj_list[current_ver][i]; 
            if (!discovered[adjacent_ver]) { 
                component.push_back(adjacent_ver); 
                discovered[adjacent_ver] = true; 
            } 
        } 
 
        front++;  
    } 
} 
 
void connected_components(graph* g) { 
    vector<bool> discovered; 
    initialize_search(g, discovered); 
 
    int component = 0; 
    for (int i = 1; i <= g->n_ver; i++) { 
        if (!discovered[i]) { 
            component++; 
            cout << "Компонент " << component << ": "; 
            bfs(g, i, discovered); 
            cout << endl; 
        } 
    } 
} 
 
int main() { 
    graph g; 
    g.n_ver = 5; // число вершин графа 
 
    g.adj_list.resize(g.n_ver + 1); 
 
    g.adj_list[1] = {2, 3}; 
    g.adj_list[2] = {1, 3}; 
    g.adj_list[3] = {1, 2, 4}; 
    g.adj_list[4] = {4}; 
    g.adj_list[5] = {};  // вершина без смежности 
 
    connected_components(&g); 
 
    return 0; 
}