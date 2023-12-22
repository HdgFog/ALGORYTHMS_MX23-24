#include <iostream>
#include <vector>

using namespace std;

//так как никто не задал,что надо искать, я просто буду искать какой то вектор с потолка
//вектор а с заданной длинной k, заданными целочисленными координатами

bool backtrack ( int array[], int arr_L, vector <int> &input ){ //перебор с возвратом, по указателю принимает вектор ,
	//и массив натуральными числами/набором координат
	
	size_t k = input.size();
    vector <int> V ;
	
	while (V.size() <= k){
		
		if (V == input) { return true;} 
			
		else {
			for (int i = 0; i < arr_L; ++i){
				V.push_back(array[i]);
				if (V <= input) {i++; }
				else {
					V.pop_back();}
			}
		}
	}
	return false;
}

int main(){
    
    vector <int>example = {3,5,2,5,3,7};
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    cout << backtrack( arr, 10, example);
    return 0;
}