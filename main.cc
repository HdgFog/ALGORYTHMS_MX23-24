#include <iostream>
#include <vector>

using namespace std;

//так как никто не задал,что надо искать, я просто буду искать какой то вектор с потолка
//вектор а с заданной длинной k, заданными целочисленными координатами

bool backtrack ( int array[], int arr_L, vector <int> &input ){ //перебор с возвратом, по указателю принимает вектор ,
	//и массив натуральными числами/набором координат
	
	size_t k = input.size();
    vector <int> V ;
	
	for (int j = 0; j < k; ++j){
		for (int i = 0; i < arr_L; ++i){
			if (array[i] == input[j]) { V.push_back(array[i]); }
		}
	}
    if (V == input) { return true;}
    else{return false;}
}

//реализация генерирования всех подмножеств

/*int Appendix1_btr(int array[], int leight, int n){
    
    vector <vector<int>> answer;
    vector <int> V;
    for (int i = 0; i < n; ++i){
        
    }
    
}
*/
int main(){
    
    vector <int>example = {3,5,2,5,3,7};
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    cout << backtrack( arr, 10, example);
    return 0;
}

