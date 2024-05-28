// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

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

#endif  // INCLUDE_BST_H_
