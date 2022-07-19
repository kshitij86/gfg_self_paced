#include "tree.h"

// print nodes ata a distance k from the root
// distance is the number of edges

/*
					       f(10, 2, 0);
			 /                             \
		f(7, 2, 1);                              f(19, 2, 1);
	  /           \                      /                    \
   f(NULL)     f(6, 2, 2); print(6)  f(12, 2, 2); print(12)   f(NULL)


*/

// void recur(TreeNode *root, int k, int i) {
// 	if (root == NULL) {
// 		// empty tree
// 		return;
// 	}
// 	if (i == k) {
// 		// we have crossed k levels including the root
// 		// so nodes at this level can be printed
// 		cout << root->data << endl;
// 	}
// 	// call for left tree
// 	recur(root->left, k, i + 1);
// 	// call for right tree
// 	recur(root->right, k, i + 1);
// }

// void nodes_at_k(TreeNode *root, int k) {
// 	recur(root, k, 0);
// }

void nodes_at_k_o(TreeNode *root, int k) {
	// same as above but without auxiliary function
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root-> data << endl;
	}
	nodes_at_k_o(root->left, k - 1);
	nodes_at_k_o(root->right, k - 1);
}


int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);

	nodes_at_k_o(root, 2);

}