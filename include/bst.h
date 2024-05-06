// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
};

template <typename T>
Node<T>* makeTree(const char* filename);

template <typename T>
void insert(Node<T>*& root, Node<T>* node);

template <typename T>
Node<T>* search(Node<T>* root, const std::string& word);

template <typename T>
void printTree(Node<T>* root);

#endif  // INCLUDE_BST_H_
