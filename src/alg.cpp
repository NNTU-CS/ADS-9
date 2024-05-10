// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
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
  return (hl > hr) ? (hl + 1) : (hr + 1);
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
BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
  }
  BST<std::string> bst;
  int flag = 0;
  char ch;
  std::string word;
  while (!file.eof()) {
    ch = file.get();
		if (ch >= 'A' and ch <= 'Z') {
      ch = ch + ('a' - 'A');
    }
    if (ch >= 'a' and ch <= 'z' and flag == 0) {
      flag = 1;
      word = ch;
    } else if (ch >= 'a' and ch <= 'z' and flag == 1) {
      word += ch;
    } else {
      flag = 0;
      bst.add(word);
      word = "";
    }
  }
  file.close();
  return bst;
}
