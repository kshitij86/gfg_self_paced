#include "tree.h"

// print the left view of the tree
// probably the first element of level order traversal

int maxLevel = 0;

// recursive version using preorder traversal
void left_view_recur(TreeNode *root, int level) {
	// uses preorder traversal to print the left nodes first
	if (root == NULL) {
		return;
	}
	if (maxLevel < level) {
		cout << root->data << " ";
		maxLevel = level;
	}
	left_view_recur(root->left, level + 1);
	left_view_recur(root->right, level + 1);
}

// iterative version using bfs
void left_view_iter(TreeNode *root) {
	queue<TreeNode *> bfs_q;
	bfs_q.push(root);
	while (bfs_q.empty() == false) {
		int lvl_size = bfs_q.size();
		vector<int> curr_lvl;
		while (lvl_size--) {
			TreeNode *temp = bfs_q.front();
			bfs_q.pop();
			curr_lvl.push_back(temp->data);
			if (temp->left) {
				bfs_q.push(temp->left);
			}
			if (temp->right) {
				bfs_q.push(temp->right);
			}
		}
		cout << curr_lvl[0] << " ";
	}
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);
	root->right->right = new TreeNode(45);

	left_view_recur(root, 1);
	cout << endl;
	left_view_iter(root);
}