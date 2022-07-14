#include <bits/stdc++.h>
using namespace std;

/*
	given n numbers in the range [1...n+1]
	so one number is missing, find it using bit magic

*/

int miss_n(vector<int> &a) {
	int n = a.size();
	// sum of n+1 natural numbers
	int tot_sum = ((n + 1) * (n + 2)) / 2;
	int miss_sum = 0;
	for (auto i : a) {
		miss_sum += i;
	}
	return (tot_sum - miss_sum);
}

// using xor this can be solved as
// take xor of all array numbers
// take xor of all numbers from 1 to n+1
// take xor of these results
// the number obtained is missing
// ans = (1^2^3...^n+1) ^ (a[0]^a[1]...^a[n-1])
int miss_o(vector<int> &a) {
	int n = a.size();
	int ans = 0;
	for (int i = 1; i <= n + 1; i++) {
		ans ^= i;
	}
	for (int i = 0; i < n; i++) {
		ans ^= a[i];
	}
	return ans;
}

int main() {
	// 1 missing
	vector<int> a = {2, 3, 1};
	cout << miss_n(a) << endl;
}