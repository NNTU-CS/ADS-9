#ifndef BST_H
#define BST_H

#include <string>
template <class T>
class BSTNode {
public:
    T data;
    int count;
    BSTNode* left;
    BSTNode* right;
    BSTNode(T value) : data(value), count(1), left(nullptr), right(nullptr) {}
};
template <class T>
class BST {
private:
    BSTNode<T>* root;
    void addWord(BSTNode<T>*& node, const T& value);
    void inOrder(BSTNode<T>* node) const;
public:
    BST();
   ~BST();
    void addNode(const T& value);
    void displayInOrder() const;
};
#endif
template <class T>
BST<T>::BST() : root(nullptr) {}
template <class T>
BST<T>::~BST() {}
template <class T>
void BST<T>::addWord(BSTNode<T>*& node, const T& value) {
    if (node == nullptr) {
        node = new BSTNode<T>(value);
    } else if (value < node->data) {
        addWord(node->left, value);
    } else if (value > node->data) {
        addWord(node->right, value);
    } else {
        node->count++;
    }
}
template <class T>
void BST<T>::addNode(const T& value) {
    addWord(root, value);
}
template <class T>
void BST<T>::inOrder(BSTNode<T>* node) const {
    if (node != nullptr) {
      inOrder(node->left);
      std::cout << node->data << " - " << node->count << std::endl;
      inOrder(node->right);
    }
}
template <class T>
void BST<T>::displayInOrder() const {
    inOrder(root);
}
// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Error opening file." << std::endl;
      return tree;
    }
  std::string word;
  while (file >> word) {
    for (char& c : word) {
      c = std::tolower(c);
      if (!isalpha(c)) {
        c = ' ';
      }
    }
    tree.addNode(word);
  }
  file.close();
  return tree;
}
