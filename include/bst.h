// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include  <iostream>
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
template<typename T>
int BST<T>::depth() {
  return depthTree(root);
}
template<typename T>
int BST<T>::depthTree(Node* root) {
  if (root == nullptr)
    return 0;
  int hl = depthTree(root->left);
  int hr = depthTree(root->right);
  return (hl > hr) ? (hl) : (hr);
}
template<typename T>
int BST<T>::search(T value) {
  return searchTree(root,value);
}
template<typename T>
int BST<T>::searchTree(Node* root,T value) {
  if (root == nullptr)
    return 0;
  else if (value < root->value)
    return searchTree(root->left, value);
  else if (value > root->value)
    return searchTree(root->right, value);
  else
    return root->count;
}
template<typename T>
void BST<T>::delTree(Node* root) {
  if (root == nullptr)
    return;
  delTree(root->left);
  delTree(root->right);
  delete root;
  root = nullptr;
}
template<typename T>
void BST<T>::print() {
  printTree(root);
}
template<typename T>
void BST<T>::printTree(Node* root) {
  if (root == nullptr)
    return;
  printTree(root->left);
  for (int i = 0; i < root->count; i++)
    std::cout << root->value << " ";
  printTree(root->right);
}
template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
  if (root == nullptr) {
    root = new Node;
    root->value = value;
    root->count = 1;
    root->left = root->right = nullptr;
  } else if (root->value > value) {
    root->left = addNode(root->left, value);
  } else if (root->value < value) {
    root->right = addNode(root->right, value);
  } else {
    root->count++;
  }
	return root;
}
template<typename T>
void BST<T>::add(T value) {
  root = addNode(root, value);
}
template<typename T>
BST<T>::BST() {
  root = nullptr;
}
template<typename T>
BST<T>::~BST() {
  if (root)
    delTree(root);
}
#endif  // INCLUDE_BST_H_
