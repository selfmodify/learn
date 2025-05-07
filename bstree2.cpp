#include <iostream>

using namespace std;

typedef int64_t MyData;

struct Node {
	Node* left = nullptr;
	MyData value;
	Node* right = nullptr;
	Node(MyData value) {
		this->value = value;
	}
};

class BSTree {
public:
	bool AddNode(const MyData value) {
		if (root_ == nullptr) {
			root_ = new Node(value);
			return true;
		}
		// Traverse the tree to find the location where this new node should be inserted
		Node* parent = nullptr;
		Node* curr = root_;
		while (curr != nullptr) {
			if (value == curr->value) {
				return false;
			}
			if (value < curr->value) {
				parent = curr;
				curr = curr->left;
			}
			else if (value > curr->value) {
				parent = curr;
				curr = curr->right;
			}
		}
		if (value < parent->value) {
			parent->left = new Node(value);
		}
		else {
			parent->right = new Node(value);
		}
		return true;
	}

	void Inorder() {
		cout << "\nInorder: ";
		inorder(root_);
	}

	void DeleteNode(const MyData value) {
		cout << "\nDeleting value: " << value;
		if (root_ == nullptr) {
			return;
		}
		// find the node to delete.
		Node* node = root_;
		Node*& parent = root_;
		while (node != nullptr) {
			if (value == node->value) {
				if (node->left == nullptr) {
					if (parent == node) {
						// the node was the root node.
						parent = parent->right;
					} else if (parent->left == node) {
						parent->left = node->right;
					}
					else {
						parent->right = node->right;
					}
					delete node;
					return;
				} else if (node->right == nullptr) {
					if (parent == node) {
						// the node was the root node.
						parent = parent->left;
					} else if (parent->right == node) {
						parent->right = node->left;
					}
					else {
						parent->left = node->left;
					}
					delete node;
					return;
				}
				else {
					parent = node;
					Node* successor = node->right;
					while (successor->left != nullptr) {
						parent = successor;
						successor = successor->left;
					}
					node->value = successor->value;
					parent->right = successor->right;
					delete successor;
					return;
				}
			}
			parent = node;
			if (value < node->value) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
	}
private:
	void inorder(Node* node) {
		if (node == nullptr) {
			return;
		}
		if (node->left != nullptr) {
			inorder(node->left);
		}
		cout << node->value << " ";
		if (node->right != nullptr) {
			inorder(node->right);
		}
	}
	Node* root_ = nullptr;
};

void test_null_tree() {
	cout << "\n== Testing null tree ==";
	BSTree tree;
	tree.Inorder();
	tree.DeleteNode(200);
	tree.Inorder();
	cout << "\n";
}

void test_only_root_node_tree() {
	cout << "\n== Testing tree with just root node ==";
	BSTree tree;
	for (MyData i : {200}) {
		tree.AddNode(i);
	}
	tree.Inorder();
	tree.DeleteNode(10);
	tree.Inorder();
	tree.DeleteNode(200);
	tree.Inorder();
	cout << "\n";
}

void test_only_left_subtree() {
	cout << "\n== Testing tree with 2 nodes. Right subtree is null ==";
	BSTree tree;
	for (MyData i : {200, 150}) {
		tree.AddNode(i);
	}
	tree.Inorder();
	tree.DeleteNode(200);
	tree.Inorder();
	tree.AddNode(25);
	tree.Inorder();
	cout << "\n";
}

void main3() {
	test_null_tree();
	test_only_root_node_tree();
	test_only_left_subtree();
}