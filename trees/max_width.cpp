#include "tree.h"

int max_width(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	// at least one node is present
	int max_w = INT_MIN;
	queue<TreeNode  *> q;
	q.push(root);
	while (q.empty() == false) {
		int lvl_size = q.size();
		max_w = max(max_w, lvl_size);
		while (lvl_size > 0) {
			TreeNode *temp = q.front();
			q.pop();
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
			lvl_size--;
		}
	}
	return max_w;
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);
	root->left->left = new TreeNode(6);
	root->right->right = new TreeNode(12);

	cout << max_width(root) << endl;
}