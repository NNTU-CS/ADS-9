// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>

template <typename T>
class BST {
 public:
    BST();
    int depth();
    void append(T);
    int search(T);
    struct Tree {
        Tree* right;
        Tree* left;
        int с;
        T info;
    };
 private:
    int getDepth(Tree*);
    Tree* newTree(Tree*, T);
    Tree* treeRoot;
    int findTree(Tree*, T);
};
template <typename T>
BST <T>::BST() : treeRoot(nullptr) {}
template <typename T>
typename BST <T>::Tree* BST <T>::newTree(Tree* treeRoot, T info) {
    if (treeRoot == nullptr) {
        treeRoot = new Tree;
        (*treeRoot).info = info;
        (*treeRoot).с = 1;
        (*treeRoot).left = (*treeRoot).right = nullptr;
    } else if ((*treeRoot).info < info) {
        (*treeRoot).right = newTree((*treeRoot).right, info);
    } else if ((*treeRoot).info > info) {
        (*treeRoot).left = newTree((*treeRoot).left, info);
    } else {
        (*treeRoot).с++;
    }
    return treeRoot;
}
template <typename T>
void BST <T>::append(T info) {
    treeRoot = newTree(treeRoot, info);
}
template <typename T>
int BST<T>::getDepth(Tree* treeRoot) {
    if (treeRoot != nullptr) {
        int depthLeft = getDepth((*treeRoot).left);
        int depthRight = getDepth((*treeRoot).right);
        if (depthLeft < depthRight) {
            return depthRight + 1;
        } else {
            return depthLeft + 1;
        }
    } else {
        return 0;
    }
}
template <typename T>
int BST<T>::depth() {
    return getDepth(treeRoot) - 1;
}
BST<std::string> makeTree(const char* filename);
template <typename T>
int BST<T>::findTree(Tree* treeRoot, T value) {
    if (treeRoot == nullptr) {
        return 0;
    } else if ((*treeRoot).info > value) {
        return findTree((*treeRoot).left, value);
    } else if ((*treeRoot).info == value) {
        return (*treeRoot).с;
    } else {
        return findTree((*treeRoot).right, value);
    }
}
template <typename T>
int BST<T>::search(T f) {
    return findTree(treeRoot, f);
}
#endif  // INCLUDE_BST_H_
