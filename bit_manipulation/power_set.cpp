#include <bits/stdc++.h>
using namespace std;

// program to print all subseqences using bit manipulation
// the idea is to check for each bit in the number whether/ the ith bit is set
// if it is set, then add the corresponding element to the subset, otherwise not
// this should take o(2^N) 

// Algorithm:
// 1. The idea is to check all numbers in the range (0 - (2^n)-1) 

void print_vecv(vector<vector<int>> &A){
	for(auto i: A){
		if(i.size() == 0){
			cout << "<empty>\n";
			continue;
		}
		for(auto j: i){
			cout << j << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> subset_generate(vector<int> &A){
	// total time complexity = O(2^n * n)
	// total space complexity = O(2^n) + O(n)
	int n = A.size();
	// for any set of size n, the length of the largest subset is n
	// the smallest set of any element is of size zero
	vector<vector<int>> res;
	// how can we can we check if the ith bit is set in a number?
	// we can take and with 1 << i, which will check the ith bit
	for(int i=0; i<=pow(2, n)-1; i++){
		vector<int> temp = {};
		for(int j=0; j<n; j++){
			if(i & (1<<j)){
				temp.push_back(A[j]);
			}
		}
		res.push_back(temp);
	}
	return res;
}

int main(){
	vector<int> A = {1,2};
	vector<vector<int>> res = subset_generate(A);
	print_vecv(res);
}	