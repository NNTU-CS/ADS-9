// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
template<typename T>
struct Node {
    T data;
    int count;
    Node* left, * right;
    explicit Node(T k) : data(k), count(1), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
 private:
   
    Node<T>* data;

    int Height(Node<T>* p) {
        if (p == nullptr) {
            return 0;
        }
        return std::max(Height(p->right), Height(p->left)) + 1;
    }

    Node<T>* insert(Node<T>* p, T k) {
        if (p == nullptr) {
            return new Node<T>(k);
        }
        else if (k < p->data) {
            p->left = insert(p->left, k);
        }
        else if (k > p->data) {
            p->right = insert(p->right, k);
        }
        else {
            p->count++;
        }
        return p;
    }

    int find(Node<T>* p, T k) {
        if (p == nullptr) {
            return 0;
        }
        else if (k == p->data) {
            return p->count;
        }
        else if (k < p->data) {
            return findVal(p->left, k);
        }
        else {
            return findVal(p->right, k);
        }
    }

    void deleteTree(Node<T>* p) {
        if (p == nullptr) {
            return;
        }
        deleteTree(p->right);
        deleteTree(p->left);
        delete p;
    }

 public:
    BST() : data(nullptr) {}

    void insert(T k) {
        data = insert(data, k);
    }

    int depth() {
        return Height(data) - 1;
    }

    int search(T k) {
        return find(data, k);
    }

    ~BST() {
        deleteTree(data);
    }
};
#endif  // INCLUDE_BST_H_
