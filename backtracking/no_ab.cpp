#include <bits/stdc++.h>
using namespace std;

// print all permutatins of the string using backstracking
// where "AB" is not present

void permutation_no_ab(int l, int r, string s) {
	// works correctly
	// if sometime we were going to get AB, we dont explore that path further
	// this backtracks from that step
	if (l == r) {
		cout << s << endl;
	}
	for (int i = l; i <= r; i++) {
		if (l != 0 && s[l - 1] == 'A' && s[i] == 'B') {
			return;
		}
		swap(s[l], s[i]);
		permutation_no_ab(l + 1, r, s);
		swap(s[l], s[i]);
	}
}

int main() {
	string s = "ABCD";
	permutation_no_ab(0, s.length() - 1, s);
}