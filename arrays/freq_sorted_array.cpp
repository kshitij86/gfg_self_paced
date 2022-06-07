#include <bits/stdc++.h>
using namespace std;

void freq_sorted(vector<int> &A) {
	// corner case is when all elements are same or there are no elements
	if (A.size() == 0) {
		cout << 0 << endl;
		return;
	}
	// cc = 1
	// [10, 10, 10, 20]
	int curr_count = 1, curr_ele = A[0];
	for (int i = 1; i < A.size(); i++) {
		if (curr_ele == A[i]) {
			curr_count++;
		} else {
			cout << A[i - 1] << " : " << curr_count << endl;
			curr_count = 1;
			curr_ele = A[i];
		}
	}
	cout << A[A.size() - 1] << " : " << curr_count << endl;
}

int main() {
	vector<int> A = {10, 10, 20, 20, 20, 30}, B = {10, 20, 30};
	freq_sorted(A);
	cout << "-------" << endl;
	freq_sorted(B);
}