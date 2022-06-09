// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
BST() {
root = nullptr;
}
~BST() {}
void add(T value) {
root = addNode(root, value);
}
int depth() {
return (depthTree(root) - 1);
}
int search(T value) {
return (searchNode(root, value) + 1);
}

 private:
struct Node {
T value;
int amount{};
Node* leftBr{};
Node* rightBr{};
};
Node* root;
Node* addNode(Node*, T);
int depthTree(Node*);
int searchNode(Node*, T);
};
template <typename T>
typename BST <T >::Node* BST <T >::addNode(Node* root, T val) {
if (!root) {
root = new Node;
root -> value = val;
root -> leftBr = root -> rightBr = nullptr;
} else if (root -> value > val) {
root -> leftBr = addNode(root -> leftBr, val);
} else if (root->value < val) {
root -> rightBr = addNode(root -> rightBr, val);
} else {
(root -> amount)++;
}
return root;
}
template <typename T>
int BST<T>::depthTree(Node* root) {
if (!root) {
return 0;
} else {
int LT = depthTree(root->leftBr);
int RT = depthTree(root->rightBr);
if (RT > LT) {
return RT + 1;
} else {
return LT + 1;
}
}
}
template <typename T>
int BST<T>::searchNode(Node* root, T val) {
Node* t = root;
if (!root) {
return 0;
} else if (root -> value == val) {
return root -> amount;
} else if (root -> value > val) {
return searchNode(root -> leftBr, val);
} else {
return searchNode(root -> rightBr, val);
}
}
#endif  // INCLUDE_BST_H_
