#include <iostream>
#include <vector>
using namespace std;

// Функция для обмена значений
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Рекурсивная функция для генерации всех перестановок
void generatePermutations(vector<int>& arr, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = start; i <= end; i++) {
            swap(arr[start], arr[i]);
            generatePermutations(arr, start + 1, end);
            swap(arr[start], arr[i]); // восстановление исходного массива
        }
    }
}

int main() {
    vector<int> input = {1, 2, 3};
    generatePermutations(input, 0, input.size() - 1);
    return 0;
}
