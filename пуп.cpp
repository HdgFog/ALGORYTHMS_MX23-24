#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> parent = {0, 1, 1, 2}; //Пример значения вектора parent
//Cоздается вектор, который представляет собой 
//массив родительских вершин для каждой вершины графа
bool finished = false;

void findpath(int start, int end, const vector<int>& parent) {
//Функция findpath рекурсивно находит путь от вершины start до вершины end 
//используя вектор родителей parent
    if (start == end) {
        cout << end << " ";
    } else {
        findpath(start, parent[end], parent);
        cout << end << " ";
    }
}

void process_edge(int x, int y){
// Функция process_edge проверяет, является ли ребро между вершинами x и y обратным 
//(если вершина y не является родителем вершины x)
//Если обратное ребро найдено, функция выводит цикл и путь в этом цикле
//с помощью функции findpath.
    if(parent[y] != x){ /*Найдено обратное ребро!*/
        printf("Cycle from %d to %d:", y, x);
        findpath(y, x, parent);
        finished = true;
    }
}

int main(){
    process_edge(1, 2);
    return 0;
}