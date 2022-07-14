#include <bits/stdc++.h>
using namespace std;

// return the only number occuring odd times

int odd_occ_n(vector<int> &a) {
	int m = *max_element(a.begin(), a.end());
	int f[m + 1] = {0};
	for (auto i : a) {
		f[i]++;
	}
	for (int i = 0; i < m + 1; i++) {
		if (f[i] % 2 != 0) {
			return i;
		}
	}
	// never reach here
	return - 1;
}

/*
	based on property of xor:

	x ^ x = 0
	x ^ y = y ^ x
	x ^ 0 = x

	if we do xor of elements occuring even number of times, then
	they will all be 0

	at last we can do xor of 0 with the ans and result is ans
	so simply do xor of all numbers

	since it is guranteed that only one number is odd number of times
*/

int odd_occ_o1(vector<int> &a) {
	int res = a[0];
	for (int i = 1; i < a.size(); i++) {
		res ^= a[i];
	}
	return res;
}

int main() {
	vector<int> a = {4, 4, 5, 5, 6, 6, 6, 6, 7};
	cout << odd_occ_o1(a) << endl;
}