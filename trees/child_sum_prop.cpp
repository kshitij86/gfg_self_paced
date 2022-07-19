#include "tree.h"

// check if a tree follows child sum property
// child sum -> node->data = node->left->data + node->right->data; for all nodes in tree


/*
				10
			   /  \
              7     3
             / \   / \
            2  5   1 2
*/

// TODO: the placement of base cases and recursive calls
// O(n) time, O(n) space
bool is_child_sum(TreeNode *root) {
	// for an empty tree
	if (root == NULL) {
		return true;
	}
	// base case for leaf nodes
	if (root->left == NULL && root->right == NULL) {
		return true;
	}
	// process current node
	// for the case of missing left and right
	int sum = 0;
	if (root->left) {
		sum += root->left->data;
	}
	if (root->right) {
		sum += root->right->data;
	}
	return ((root->data == sum) && is_child_sum(root->left) && is_child_sum(root->right));
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(8);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(2);

	cout << is_child_sum(root) << endl;
}