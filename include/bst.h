// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
	struct Node {
		T value;
		int count;
		Node* left;
		Node* right;
	};
	Node* root;
	Node* addNode(Node* root,T value);
	int depthTree(Node*);
	int searchTree(Node*,T value);
	void delTree(Node*);
	void printTree(Node*);

 public:
	BST();
	~BST();
	void add(T value);
	void print();
	int depth();
	int search(T value);
};
#endif  // INCLUDE_BST_H_
