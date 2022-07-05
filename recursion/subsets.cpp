#include <vector>
#include <iostream>
using namespace std;

void print_vvi(vector<vector<int>> &A){
	for(auto i: A){
		if(!i.size()){
			cout << "<empty>" << endl;
			continue;
		}
		for(auto j: i){
			cout << j << " ";
		}
		cout << endl;
	}
}

// it is similar to generating all subsequences of a string/array
// better method is using bit manipulation
// this is recursive code that either picks or does not pick an element
void gen_subsets(int idx, int n, vector<int> &A, vector<int> &current, vector<vector<int>> &subsets){
	if(idx >= n){
		subsets.push_back(current);
		return;
	}
	// pick an element
	current.push_back(A[idx]);
	gen_subsets(idx+1, n, A, current, subsets);
	// dont take irt
	current.pop_back();
	gen_subsets(idx+1, n, A, current, subsets);
}

int main(){
	int idx = 0;
	vector<int> A = {1,2,3};
	vector<int> current;
	vector<vector<int>> subsets;
	gen_subsets(idx, A.size(), A, current, subsets);
	print_vvi(subsets);
}
