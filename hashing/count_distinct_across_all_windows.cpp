#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int> &A) {
	for (auto i : A) {
		cout << i << " ";
	}
	cout << endl;
}

map<int, int> map_insert(map<int, int> m1, int X) {
	if (m1.find(X) == m1.end()) {
		m1[X] = 1;
	} else {
		m1[X]++;
	}
	return m1;
}

vector<int> count_distinct(vector<int> &A, int K) {
	// there are at max (N - K + 1) windows of size K in array of size N
	vector<int> B;
	map<int, int> freq_map;
	// add K elements to the map already
	for (int i = 0; i < K; i++) {
		freq_map = map_insert(freq_map, A[i]);
	}

	// O(N) solution to
	for (int i = 0; i <= A.size() - K; i++) {
		// add current count of distinct elements
		B.push_back(freq_map.size());
		// remove first element of previous window
		freq_map[A[i]]--;
		if (freq_map[A[i]] == 0) {
			freq_map.erase(A[i]);
		}
		// add element just outside of window
		freq_map = map_insert(freq_map, A[i + K]);
	}
	return B;
}

int main() {
	// window size
	int K = 3;
	// input array
	vector<int> A = {1, 2, 3, 4, 4, 3, 2};
	vector<int> res = count_distinct(A, K);
	print_array(res);
}