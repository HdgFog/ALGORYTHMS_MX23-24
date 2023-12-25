#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 5; // количество вершин
    vector<vector<int>> adj(n);

    // добавляем ребра
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(1);

    // проверка наличия цикла
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    bool foundCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            for (int u : adj[i]) {
                if (!visited[u]) {
                    parent[u] = i;
                    visited[u] = true;
                } else if (u != parent[i]) {
                    foundCycle = true;
                    break;
                }
            }
        }
    }

    if (foundCycle) {
        cout << "Граф содержит цикл" << endl;
    } else {
        cout << "Граф не содержит цикл" << endl;
    }

    return 0;
}