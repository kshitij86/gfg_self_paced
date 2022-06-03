#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
/**
 *
 * Objective is to find the maximum difference between
 * A[i] and A[j] such that j > i
 *
 */
int max_diff_naive(vector<int> &A) {
	// O(N^2) solution
	int max_diff = INT_MIN;
	for (int i = 0; i < A.size() - 1; i++) {
		for (int j = i + 1; j < A.size(); j++) {
			int diff = A[j] - A[i];
			max_diff = max(max_diff, diff);
		}
	}
	return max_diff;
}

int max_diff_optimal(vector<int> &A) {
	// can be solved similar to leaders
	// [2,3,10,6,4,8,1]
	// i = 5, max_diff = -7, max_ele = 8
	// i = 4, max_diff = 4, max_ele = 8
	// i = 3, max_diff = 4, max_ele = 8
	// i = 2, max_diff = 4, max_ele = 10
	// i = 1, max_diff = 7, max_ele = 10
	// i = 0, max_diff = 8, max_ele = 10
	// here curr_diff is used to compare with the max_diff
	// and maximum element is also store as max_ele
	// for each element A[i], we are searching for the maximum to its right
	// so starting traversal from right we can get both
	int max_diff = INT_MIN, max_ele = A[A.size() - 1];
	for (int i = A.size() - 2; i >= 0; i--) {
		int curr_diff = max_ele - A[i];
		// check for max_diff
		max_diff = max(max_diff, curr_diff);
		// check for max_ele in right subarray
		max_ele = max(max_ele, A[i]);
	}
	return max_diff;
}

// can also be done by travsersing from left to right and
// keeping track of min_ele ansd max_diff

int main() {
	vector<int> A = {2, 3, 10, 6, 4, 8, 1},
	            B = {7, 9, 5, 6, 3, 2},
	            C = {10, 20, 30},
	            D = {30, 10, 8, 2};
	cout << max_diff_optimal(A) << endl;
	cout << max_diff_optimal(B) << endl;
	cout << max_diff_optimal(C) << endl;
	cout << max_diff_optimal(D) << endl;
}