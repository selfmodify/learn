// Create a binary search tree and perform various operations on it.

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};

class BSTree {
public:
	void insert(int value) {
		cout << "" << value << " ";
		insert(root, value);
	}

	void dfs() {
		cout << "DFS:\n";
		dfs(root);
		cout << "\n";
	}
	void bfs() {
		cout << "BFS:\n";
		queue<Node*> q1;
		queue<Node*> q2;
		q1.push(root);
		while (!q1.empty() || !q2.empty()) {
			if (!q1.empty()) {
				while (!q1.empty()) {
					Node* n = q1.front();
					q1.pop();
					if (n != nullptr) {
						cout << n->data << " ";
						q2.push(n->left);
						q2.push(n->right);
					}
				}
				cout << "\n";
			}
			if (!q2.empty()) {
				while (!q2.empty()) {
					Node* n = q2.front();
					q2.pop();
					if (n != nullptr) {
						cout << n->data << " ";
						q1.push(n->left);
						q1.push(n->right);
					}
				}
				cout << "\n";
			}
		}
		cout << "\n";
	}
	
	bool delete_node_internal(int value) {
		if (root == nullptr) {
			return false;
		}
		Node* curr = root;
		Node* node = nullptr;
		Node* parent = nullptr;
		while (curr != nullptr) {
			if (curr->data == value) {
				node = curr;
				break;
			}
			if (value < curr->data) {
				parent = curr;
				curr = curr->left;
			}
			else {
				parent = curr;
				curr = curr->right;
			}
		}
		if (node == nullptr) {
			// not found.
			return false;
		}
		if (node->left == nullptr && node->right != nullptr) {
			// only has right child
			parent->data = node->data;
			parent->right = node->right;
			parent->left = node->left;
			delete node;
			return true;
		} else if (node->left != nullptr && node->right == nullptr) {
			// only has left child
			parent->data = node->data;
			parent->right = node->right;
			parent->left = node->left;
			delete node;
			return true;
		}
		else if (node->left == nullptr && node->right == nullptr) {
			if (parent == nullptr) {
				// if parent is null then this is the root node.
				delete root;
				root = nullptr;
				return true;
			}
			// leaf node
			if (parent->left == node) {
				parent->left = nullptr;
				delete node;
				return true;
			}
			else {
				parent->right = nullptr;
				delete node;
				return true;
			}
		}
		else {
			// both left and right nodes exist. Find the infix successor node.
			Node* succ = node->right;
			Node* succ_parent = nullptr;
			while (succ->left != nullptr) {
				succ_parent = succ;
				succ = succ->left;
			}
			succ_parent->left = succ->right;
			node->data = succ->data;
			delete succ;
			return true;
		}
		return false;
	}
	
	void delete_node(int value) {
		cout << "Deleting node " << value << " " << delete_node_internal(value) << "\n";
	}
private:
	void insert(Node*& node, int value) {
		if (node == nullptr) {
			node = new Node(value);
		}
		else if (value < node->data) {
			if (node->left == nullptr) {
				node->left = new Node(value);
			}
			else {
				insert(node->left, value);
			}
		}
		else if (value > node->data) {
			if (node->right == nullptr) {
				node->right = new Node(value);
			}
			else {
				insert(node->right, value);
			}
		}
	}

	void dfs(Node* node) {
		if (node == nullptr) {
			return;
		}
		if (node->left != nullptr) {
			dfs(node->left);
		}
		if (node->right != nullptr) {
			dfs(node->right);
		}
		cout << node->data << "\n";

	}

	Node* root = nullptr;
};

int main() {
	cout << std::boolalpha;
	BSTree bstree;
	cout << "Inserting: ";
	for (int v : {300, 267, 1400, 1378, 1390, 1385, 1443, 250, 255, 1790}) {
		bstree.insert(v);
	}
	cout << "\n";
	// bstree.dfs();
	bstree.bfs();
	bstree.delete_node(300);
	cout << "BFS after delete operation.";
	bstree.bfs();
}
