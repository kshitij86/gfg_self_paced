#include <bits/stdc++.h>
using namespace std;

// count all the set bits in all numbers from 1 to n

int max2(int n) {
	// return the max power of 2 closest to this number
	int c = 0;
	while ((1 << c) < n) {
		c++;
	}
	return c - 1;
}

int count_total_set(int n) {
	if (n == 0) {
		return 0;
	}
	int x = max2(n);
	int ans = x * ((1 << (x - 1)) + (n - (1 << x)) + 1 + count_total_set(n - (1 << x)));
	return ans;
}


int main() {
	int n = 17;
	cout << count_total_set(n) << endl;
}