/// @file Listing_9_2.cpp
/// @brief Implementation of the backtracking algorithm
/// @author's Shemyakin Dmitriy Krykovich Sonya Solonitsyn Maksim

/// Можно написать реализацию алгоритма для произвольной структуры данных, здесь представлена реализация для задачи коммивояжера.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAXCITIES = 10; // Максимальное количество городов

struct Data {
    int distance[MAXCITIES][MAXCITIES];
    int numCities;
};

bool isASolution(int a[], int k, const Data& input) {
    return k == input.numCities;
}

void processSolution(int a[], int k, const Data& input) {
    std::cout << "Tour: ";
    for (int i = 0; i < k; ++i) {
        std::cout << a[i] << " ";
    }

    int totalDistance = 0;
    for (int i = 0; i < k - 1; ++i) {
        totalDistance += input.distance[a[i]][a[i + 1]];
    }
    totalDistance += input.distance[a[k - 1]][a[0]]; // Вернуться в начальный город

    std::cout << "\nTotal Distance: " << totalDistance << "\n";
}

void constructCandidates(int a[], int k, const Data& input, int c[], int* nc) {
    for (int i = 0; i < input.numCities; ++i) {
        c[i] = i;
    }
    *nc = input.numCities;
}

void backtrack(int a[], int k, const Data& input) {
    int c[MAXCITIES];
    int nc;

    if (isASolution(a, k, input)) {
        processSolution(a, k, input);
    } else {
        constructCandidates(a, k, input, c, &nc);

        for (int i = 0; i < nc; ++i) {
            std::swap(c[i], c[k]);
            a[k] = c[k];
            backtrack(a, k + 1, input);
            std::swap(c[i], c[k]);
        }
    }
}

int main() {
    Data input;

    input.numCities = 4;
    input.distance[0][1] = 10;
    input.distance[0][2] = 15;
    input.distance[0][3] = 20;
    input.distance[1][0] = 10;
    input.distance[1][2] = 25; // Расстояние от города 1 до города 2
    input.distance[1][3] = 35; // Расстояние от города 1 до города 3
    input.distance[2][0] = 15;
    input.distance[2][1] = 25;
    input.distance[2][3] = 30; // Расстояние от города 2 до города 3
    input.distance[3][0] = 20;
    input.distance[3][1] = 35;
    input.distance[3][2] = 30;

    int a[MAXCITIES] = {0}; // Инициализация массива для хранения перестановок городов

    backtrack(a, 0, input);

    return 0;
}