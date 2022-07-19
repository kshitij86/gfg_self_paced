#include "tree.h"

/*

		 10
		/  \
	   7     19
	  / \   /  \
	     6  12  34
	              \
	               60


*/

int height(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

bool is_balanced(TreeNode *root) {
	if (root == NULL) {
		return true;
	}
	int lefth = height(root->left);
	int righth = height(root->right);

	return (abs(lefth - righth) < 2) && is_balanced(root->left) && is_balanced(root->right);
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);
	root->right->right = new TreeNode(34);
	root->right->right->right = new TreeNode(60);

	cout << is_balanced(root) << endl;
}