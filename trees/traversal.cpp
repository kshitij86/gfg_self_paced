// testing tree.h
#include "tree.h"

/*
	tree structure -

	 			10
			   /  \
			  7   19
			  \   /
			  6   12
*/

void inorder(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	inorder(root->left);
	inorder(root->right);
}

void postorder(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	inorder(root->right);
	cout << root->data << " ";
}


int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);
	inorder(root); cout << "\n";
	preorder(root); cout << "\n";
	postorder(root);

}