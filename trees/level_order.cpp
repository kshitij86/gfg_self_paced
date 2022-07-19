#include "tree.h"

void level_order_iter(TreeNode *root) {
	// queue to store nodes
	queue<TreeNode *> bfs_queue;
	// start with the root
	bfs_queue.push(root);
	// if queue is empty all nodes have been visited
	while (bfs_queue.empty() == false) {
		// get the current level size
		// process all nodes at the current level

		TreeNode *popped_node = bfs_queue.front();
		cout << popped_node->data << " ";
		bfs_queue.pop();
		if (popped_node->left != NULL) {
			bfs_queue.push(popped_node->left);
		}
		if (popped_node->right) {
			bfs_queue.push(popped_node->right);
		}

		// to separate levels
		cout << endl;
	}
}


// another method which combines
// the height of tree and nodes at distance k

/*
	the process will first find out the height of the tree (max nodes)
	then for each k, print the nodes at height k

	below method is not efficient, takes O(n*h) time
*/

int height(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return 1 + max(height(root->left) , height(root->right));
}

void nodes_at_k(TreeNode *root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data << " ";
	}
	nodes_at_k(root->left, k - 1);
	nodes_at_k(root->right, k - 1);
	// to separate the levels
}

void level_order_recur(TreeNode *root) {
	int k = height(root);
	for (int i = 0; i < k; i++) {
		// print all the nodes at height k
		nodes_at_k(root, i);
	}
}

void bfs_line_by_line(TreeNode *root) {
	// prints each level on a new line
	queue<TreeNode *> bfs_queue;
	bfs_queue.push(root);
	while (bfs_queue.empty() == false) {
		int lvl_size = bfs_queue.size();
		while (lvl_size > 0) {
			TreeNode *popped_node = bfs_queue.front();
			bfs_queue.pop();
			cout << popped_node->data << " ";
			if (popped_node->left) {
				bfs_queue.push(popped_node->left);
			}
			if (popped_node->right) {
				bfs_queue.push(popped_node->right);
			}
			lvl_size -= 1;
		}
		cout << endl;
	}
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->right = new TreeNode(19);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->right->left = new TreeNode(12);
	root->right->right = new TreeNode(20);
	// level_order_iter(root);
	bfs_line_by_line(root);
}