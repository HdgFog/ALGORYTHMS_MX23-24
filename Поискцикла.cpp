#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> parent; //Предполагается, что этот вектор тут где-то определен
bool finished = false;

void findpath(int start, int end, const vector<int>& parent) {
    if (start == end) {
        cout << end << " ";
    } else {
        findpath(start, parent[end], parent);
        cout << end << " ";
    }
}

void process_edge(int x, int y){
//process_edge проверяет, является ли ребро обратным
//если да, то выводится цикл и путь в этом цикле
    if(parent[y] != x){/*Найдено обратное ребро!*/
        printf("Cycle from %d to %d:", y, x);
        findpath(y, x, parent);
//findpath рекурсивно находит путь от начальной вершины 
//до конечной вершины, используя вектор родителей
        finished = true;
    }
}

int main(){
    process_edge(1, 2); //Вызываем функцию с передачей ей двух вершин 1 и 2 в качестве параметров
    return 0;
}