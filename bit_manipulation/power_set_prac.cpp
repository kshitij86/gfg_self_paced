#include <bits/stdc++.h>
using namespace std;

/*
	things to note -

	need to consider the range [0, 2^n-1] for set bits

	for the number of bits, remeber that in 2^n, there will be only n bits
	equal t the length of the vector/string

*/


vector<vector<int>> power_set(vector<int> &a) {
	int n = a.size();
	int p2 = pow(2, n);
	vector<vector<int>> ans;

	for (int i = 0; i < p2; i++) {
		// include whichever characters are present
		// according to set bits in i
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			// note: just need to check that their and is not zero
			// it is not required to be 1
			if ((i & (1 << j)) != 0) {
				temp.push_back(a[j]);
			}
		}
		ans.push_back(temp);
	}
	return ans;
}

vector<string> power_string(string s) {
	int n = s.length();
	int p2 = pow(2, n);

	vector<string> ans;
	for (int i = 0; i < p2; i++) {
		string temp = "";
		for (int j = 0; j < n; j++) {
			// again, only checking that their and is non zero will do
			if ((i & (1 << j)) != 0) {
				temp += s[j];
			}
		}
		ans.push_back(temp);
	}
	return ans;
}

int main() {
	vector<int> a = {1, 2, 3};
	vector<vector<int>> ans = power_set(a);
	for (auto i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	string s = "ABCD";
	vector<string> ans2 = power_string(s);
	for (auto i : ans2) {
		cout << i << endl;
	}
}
