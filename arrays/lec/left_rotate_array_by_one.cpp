#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

void print_array(vector<int> &arr){
	for(auto i : arr){
		cout << i << " "; 
	}
	cout << endl;
}

void rotate_left_one(vector<int> &arr){
	// store first element to place at last
	int first = arr[0];
	for(int i=1; i<arr.size(); i++){
		// move all other elements to the left
		arr[i-1] = arr[i];
	}
	// place first element at last
	arr[arr.size()-1] = first;
}

int main(){
	vector<int> arr = {3,2,1,4,5,7};
	rotate_left_one(arr);
	print_array(arr);
}


