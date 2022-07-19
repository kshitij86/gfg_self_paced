#include "tree.h"

void maximum_in_tree(TreeNode *root, int *max_g) {
	if (root == NULL) {
		return;
	}
	*max_g = max(*max_g, root->data);
	maximum_in_tree(root->left, max_g);
	maximum_in_tree(root->right, max_g);
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);

	int max_g = INT_MIN;

	maximum_in_tree(root, &max_g);
	cout << max_g << endl;
}