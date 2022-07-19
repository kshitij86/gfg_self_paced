#include "tree.h"

// height of a binary tree is defined as max number of
// nodes from root to a leaf path

/*
		                  f(10); return 1 + max(2, 2) = 3
		    /                                             \
	      f(7); return 1 + max(0, 1)                     f(19); return 1 + max(0, 1)
	  /            \                                  /        \
f(NULL); return 0	f(6); returns 1            f(12); return 1       f(NULL); return 0
*/

int height(TreeNode *root) {
	if (root == NULL) {
		// an empty tree has a height of zero
		return 0;
	}
	if (root->left  == NULL && root->right == NULL) {
		// this is a leaf and it counts towards the height
		return 1;
	}
	int lefth = height(root->left);
	int righth = height(root->right);
	return 1 + max(lefth, righth);
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);

	cout << height(root) << endl;
}