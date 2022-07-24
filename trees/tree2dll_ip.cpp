#include "tree.h"

// convert a tree to a doubly linked list in place
// without using any extra space for dll nodes

// left = prev, right = next for each node
// order followed should be inorder traversal

/*
		10
	   / \
      2   3

    DLL: 2 -><- 10 -><- 3
*/

TreeNode *convert2dll_ip(TreeNode *root) {
	if (root == NULL) {
		return root;
	}
	static TreeNode *prevp = NULL;

	// left call
	TreeNode *head = convert2dll_ip(root->left);
	// process the current node
	if (prevp == NULL) {
		head = root;
	} else {
		root->left = prevp;
		prevp->right = root;
	}
	prevp = root;
	// right call
	convert2dll_ip(root->right);
	return head;
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);

	TreeNode *ll = convert2dll_ip(root);
	while (ll->right != NULL) {
		cout << ll->data << endl;
		ll = ll->right;
	}
}