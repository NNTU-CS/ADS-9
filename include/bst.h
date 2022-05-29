// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template < typename T > 
class BST {
 public:
	struct Node {
		T value;
		int count;
		Node *left, *right;
	};

 private:
  typedef Node* link;
	link root;
	link addNode(link root, T value) {
		if (root == nullptr) {
			root = new Node;
			root->value = value;
			root->count = 1;
			root->left = root->right = nullptr;
		}
		else if (root->value > value) {
			root->left = addNode(root->left, value);
		}
		else if (root->value < value) {
			root->right = addNode(root->right, value);
		}
		else
			root->count++;
		return root;
	} 
	int depthTree(link root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 0;
		int LS = depthTree(root->left);
		int RS = depthTree(root->right);
		return  1 + (LS > RS ? LS: RS);
	}
	int searchNode(link root, T value) {
		if (root == nullptr) {
			return 0;
		} else {
			if (root->value == value)
				return root->count;
			else if (root->value < value)
				return searchNode(root->right, value);
			else
				return searchNode(root->left, value);
		}
	}

public:
	BST() : root(nullptr) {}
	void add(T value) {
		root = addNode(root, value);
	}
	int depth() {
		return depthTree(root);
	}
	int search(T value) {
		return searchNode(root, value);
	}

};
#endif  // INCLUDE_BST_H_
