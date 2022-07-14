#include <bits/stdc++.h>
using namespace std;

// check if anumber is a power of 2 r not

// O(logn)
bool power_2(int n) {
	int c = 0;
	while (n) {
		cout << n << endl;
		if ((n & 1) == 1) {
			c++;
		}
		n >>= 1;
	}
	return c == 1;
}

// a power of two will only have one bit set
// brian kernighan algorithm
//  runs in better time - theta(1)
bool brian_k(int n) {
	/*
		we can unset the rightmost bit of any number n by doing
		n & n-1

		4 = 0100
		3 = 0011
		--------
		    0000

		In power of 2, there will be only one right most bit
		If after subtraction, the number becomes zero, then there was only one set bit and hence it was a power of 2
	*/
	if (n == 0) {
		return false;
	}
	return ((n & (n - 1) ) == 0);
}

int main() {
	int n = 63;
	cout << brian_k(n) << endl;
}