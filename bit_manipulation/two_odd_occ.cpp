#include <bits/stdc++.h>
using namespace std;

// given an array with two odd occuring numbers, return them both

/*
	idea is to take xor of all numbers
	the numbers occuring even number of times will vanish

	in the dn ans = x^y will be present.
	the xor of the two numbers required.
	we can separate them by doing the below

	find the bit where x^y is 1,
	this is where both numbers are different
	we can divide the array into two parts using this bit
	taking xor at each step

	at the end we will have the answer


*/

vector<int> two_odd_o(vector<int> &a) {
	int n = a.size();
	vector<int> ans(2, 0);
	int res = 0;
	for (int i = 0; i < n; i++) {
		res ^= a[i];
	}

	// res is now x^y, we can separate them
	// find out a set bit in res;
	int k = 0;
	while (res != 0) {
		if ((res & (1 << k)) == 1) {
			break;
		}
		k++;
		res >>= 1;
	}
	// the two groups are simple - is your kth bit set?
	// at the kth bit, x and y are different
	// since apart from x and y all are even times
	// they will amunt to zero in their groups and only thing left will be x or y
	// note that if x == y it appears even times, hence not possible
	for (int i = 0; i < n; i++) {
		if ((a[i] & (1 << k)) == 1) {
			ans[0] ^= a[i];
		} else {
			ans[1] ^= a[i];
		}
	}
	return ans;
}

int main() {
	vector<int> a = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};
	vector<int> res = two_odd_o(a);
	cout << res[0] << " " << res[1] << endl;
}