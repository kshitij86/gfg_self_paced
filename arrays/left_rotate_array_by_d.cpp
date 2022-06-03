#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> &arr){
	for(auto i : arr){
		cout << i << " "; 
	}
	cout << endl;
}

void rotate_by_d_extra_space(vector<int> &arr, int d){
	// circular rotations
	d %= arr.size();
	vector<int> temp(d, 0);
	// idea is to store the first d elements in an array
	// the rest will be shifted d places to the left
	// then in the remaining indices, we can place elements from the d array

	for(int i=0; i<d; i++){
		temp[i] = arr[i];
	}
	// T.C - theta(d)
	for(int i=d; i<arr.size(); i++){
		// here each i is guaranteed to be >= d as
		// we starting at d itself. so index can have i-d
		// arr[d - d] -> arr[0], i = d
		// arr[(d+1) - d] -> arr[1], i = d+1
		// and so on, each element will move to the left d places
		arr[i-d] = arr[i];
	}
	// T.c. - theta(n-d+1)
	// now place the remaining elements into places using the d array
	// just placed n-d elements into the array
	// [1,2,3,4,5,6,7], d = 3, [1,2,3]
	// [4,5,6,7,1,2,3]
	// i will start at arr.size() - d
	for(int i=0; i<d; i++){
		// start placing elements from n-d index as last element 
		// is shifted to n-d-1
		arr[(arr.size()-d)+i] = temp[i];
	}
	// T.C. - theta(d)

	// Final - theta(n - d + 1 + d + d) -> theta(n + d)
	// Space - theta(d)
}

void reverse_vector(vector<int> &arr, int a, int b){
	// simple method to reverse the array
	while(a < b){
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
		a++;
		b--;
	}
}

void rotate_by_d_optimal(vector<int> &arr, int d){
	/**
	 * recursive approach
	 * 1. reverse arr[0, d-1]
	 * 2. reverse arr[d, arr.size()-1]
	 * 3. reverse the entire array to get the left shifted array
	 * 
	 * theta(n) time, theta(1) space
	 */

	// first d elements
	reverse_vector(arr, 0, d-1);
	cout << "1: ";
	print_array(arr);
	// remaining elements
	reverse_vector(arr, d, arr.size()-1);
	cout << "2: ";
	print_array(arr);
	// entire vector
	reverse_vector(arr, 0, arr.size()-1);
	cout << "3: ";
	print_array(arr);
}
int main(){
	// every element shift 3 places to the left
	// arr[3] -> arr[1]
	// arr[5] -> arr[3]
	int d = 3;
	vector<int> arr = {1,2,3,4,5,6,7};
	// naive solution is to apply one rotation d times - theta(n*d) time
	// optimal is to do it all at once
	// it is guaranteed that there will be no collisions
	// rotate_by_d_extra_space(arr, d);
	// print_array(arr);

	// juggling algorithm
	rotate_by_d_optimal(arr, d);
	print_array(arr);
}