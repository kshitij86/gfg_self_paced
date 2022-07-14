#include <vector>
#include <iostream>
using namespace std;

// is there a subsequence of the given vector that sums upto x?

void recur(int idx, int n, int x, bool *ans, vector<int> &A, int sum){
	// our function never sets ans = false, so if a subset exists 
	// we modify ans to true and never change it
	if(idx >= n){
		// consider the current subsequence that we have picked
		if(sum == x){
			*ans = true;
		}
		
		return;
	}
	// pick this element and check
	recur(idx+1, n, x, ans, A, sum+A[idx]);
	// dont pick it
	recur(idx+1, n, x, ans, A, sum);
}

bool subset_exists(vector<int> &A, int x){
	bool ans = false;
	int idx = 0;
	int sum = 0;
	int n = A.size();
	recur(idx, n, x, &ans, A, sum);	
	return ans;
}

int main(){
	int x = 12;
	vector<int> A = {435, 787, 90, 678, 320, 482, 3, 9};
	cout << subset_exists(A, x) << endl;;
}