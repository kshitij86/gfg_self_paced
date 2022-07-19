#include "tree.h"

int size_of_tree(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return size_of_tree(root->left) + size_of_tree(root->right) + 1;
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);

	cout << size_of_tree(root) << endl;
}