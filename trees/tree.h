#include <bits/stdc++.h>
using namespace std;

// C++ treats structs as classes
// so constructrs are possible
struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};