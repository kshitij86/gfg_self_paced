#include <bits/stdc++.h>
using namespace std;

// given a string, print all n! permutations of the given string

// idea is to fix a character at some position
// mark its availability and place other characters at next places
// once all are placed, add this to the answer and move forward

// this program works using swapping
// using the current string, swap elements in it

/*

	All 6 perms of ABC
	Recursion Tree -
					              f(0, n, "ABC")
				    /                 |                           \
                "ABC"             f(1, n, "ABC")                "ABC"  (i=0, j=0)
                                /     |                           \    (i=1, j=1)
				                  f(2, n, "ABC")                       (i=2, j=2)
								   [print(ABC)]


								f(1, n, "ABC")                         (i=1, j=2)
             /			             |                  \
			"ACB"                f(2, n, "ACB")        "ABC"           (i=2, j=2)
								  [print(ACB)]

								f(0, n, "ABC")                         (i=0, j=1)
					/			     |              \
				"BAC"           f(1, n, "BAC")      "ABC"              (i=1, j=1)
                   /                 |              \
                "BAC"           f(2, n, "BAC")      "BAC"              (i=2, j=2)
                                  [print(BAC)]


								f(1, n, "BAC")						   (i=1, j=2)
                    /               |                    \
				"BCA"           f(2, n, "BCA")           "BAC"         (i=2, j=2)
								 [print(BCA)]


								f(0, n, "ABC")                         (i=0, j=2)
				/                    |                \
			"CBA"               f(1, n, "CBA")        "ABC"            (i=1, j=1)
			    /                    |                  \
            "CBA"               f(2, n, "CBA")          "CBA"          (i=2, j=2)
            					 [print(CBA)]

								f(1, n, "CBA")                         (i=1, j=2)
					/        	     |                \
                "CAB"           f(2, n , "CAB")     "CBA"              (i=2, j=2)
                			     [print(CAB)]
 */

void permutation(int i, int n, string s) {
	// base case
	// wew are the end of string
	if (i == n - 1) {
		cout << s << endl;
		return;
	}
	for (int j = i; j < n; j++) {
		// swap characters to get some permutation
		swap(s[i], s[j]);
		// call for the next index
		permutation(i + 1, n, s);
		// backtracking step to try for next index
		swap(s[i], s[j]);
		// fpr a particualr i this will try to swap all characters i+1 to j with i
		// and go forward to get a new permutation
	}
}

int main() {
	// total 6 outputs needed
	string s = "ABC";
	int n = s.length();
	vector<int> used(s.length());
	vector<string> res;
	permutation(0, n, s);
	for (auto i : res) {
		cout << i << endl;
	}
}