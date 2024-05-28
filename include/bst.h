// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int cnt;
        Node* l;
        Node* r;
    };
 private:
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
 public:
    BST();
    void add(T);
    int depth();
    int search(T);
};
template <typename T>
BST <T>::BST() : root(nullptr) {}
template <typename T>
typename BST <T>::Node* BST <T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->cnt = 1;
        root->l = root->r = nullptr;
    } else if (root->value > value) {
        root->l = addNode(root->l, value);
    } else if (root->value < value) {
        root->r = addNode(root->r, value);
    } else {
        root->cnt++;
    }
return root;
}
template <typename T>
void BST <T>::add(T value) {
    root = addNode(root, value);
}
template <typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = depthTree(root->l);
        int rightDepth = depthTree(root->r);
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
}
template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}
BST<std::string> makeTree(const char* filename);
template <typename T>
int BST<T>::searchNode(Node* root, T val) {
    if (root == nullptr)
        return 0;
    else if (root->value == val)
        return root->cnt;
    else if (root->value > val)
        return searchNode(root->l, val);
    else
        return searchNode(root->r, val);
}
template <typename T>
int BST<T>::search(T v) {
    return searchNode(root, v);
}

#endif  // INCLUDE_BST_H_
