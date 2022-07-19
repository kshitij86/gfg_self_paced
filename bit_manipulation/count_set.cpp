#include <bits/stdc++.h>
using namespace std;

int count_set_o1(int n) {
	// time = theta(count of set bits)
	// it uses brian kern algo to count bits
	// it will run only that many times as there are set bits
	// n = `15, it runs 4 times

	// bk algo will unset rightmost set bit
	// by doing n = (n & (n-1))
	// we check if n is still non zero at the end of each loop iteration

	/*
		when a number is subtracted by one, the rightmost set bit is unset
		and all unset bits to the right of that are set

		n=40	101000
		n-1=39	100111

		this is true for all numbers and a good point
	*/

	int res = 0;
	while (n > 0) {
		n = (n & (n - 1));
		res++;
	}
	return res;
}

int count_set_o2(int n) {
	// this will do the operation in O(1)
	// time and O(1) extra space
	int table[256];
	// initialize
	table[0] = 0;
	for (int i = 1; i < 256; i++) {
		table[i] = (i & 1) + table[i / 2];
	}
	int res = table[n & 0xFF];
	n >>= 8;
	res += table[n & 0xFF];
	n >>= 8;
	res += table[n & 0xFF];
	n >>= 8;
	res += table[n & 0xFF];
	return res;
}

int main() {
	int n = 63;
	cout << count_set_o2(n) << endl;
}