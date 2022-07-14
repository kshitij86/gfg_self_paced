#include<bits/stdc++.h>
using namespace std;

bool k_bit_set(int x, int k) {
	return (x & (1 << k));
}

bool k_bit_set_left(int x, int k) {
	// for this we need to know the largest
	// number that can fit in this range
	// considering input will never cross (2^32)-1
	int large = 1 << (16);
	large >>= 16 - k;
	return large & x;
}

int main() {
	int k = 7;
	int x = 9;
	cout << k_bit_set_left(x, k) << endl;
}