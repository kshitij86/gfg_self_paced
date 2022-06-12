#include <bits/stdc++.h>
using namespace std;

// given an binary array/string, return the maximum number of ones consecutive in array
// or, return the length of the longest number of consecutive ones

int max_consecutive_ones_naive(vector<int> &A) {
	// naive approach consider all subarrays
	// O(N^2) approach, not optimal
	int max_ones = 0;
	for (int i = 0; i < A.size();) {
		if (A[i] == 1) {
			int j = i, local_ones = 0;
			while (A[j] == 1) {
				local_ones++;
				j++;
			}
			i = j;
			max_ones = max(max_ones, local_ones);
		} else {
			i++;
		}
	}
	return max_ones;
}

int max_consecutive_ones_optimal(vector<int> &A) {
	// O(N) approach
	/**
	 */
	int end = 0, max_ones = 0, local_ones = 0;
	while (end < A.size()) {
		if (A[end] == 1) {
			local_ones++;
		} else {
			local_ones = 0;
		}
		max_ones = max(max_ones, local_ones);
		end++;
	}
	return max_ones;
}

int main() {
	vector<int> A = {0, 0, 0, 1, 1, 0, 1};
	cout << max_consecutive_ones_optimal(A) << endl;
}