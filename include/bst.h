// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
#include <string>

template<typename T>
struct Node {
    T key;
    int count;
    Node *left, *right;

    explicit Node(T k) : key(k), count(1), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
 private:
    Node<T> *root;

    int Height(Node<T> *point) {
        if (point == nullptr)
            return 0;
        int hr = Height(point->right);
        int hl = Height(point->left);
        return std::max(hr, hl) + 1;
    }

    Node<T> *insert(Node<T> *point, T k) {
        if (point == nullptr) {
            point = new Node<T>(k);
        } else if (point->key > k) {
            point->left = insert(p->left, k);
        } else if (point->key < k) {
            point->right = insert(point->right, k);
        } else {
            point->count++;
        }
        return point;
    }

    int findV(Node<T> *point, T k) {
        if (point->key == k)
            return point->count;
        else if (point->key > k)
            return findV(point->left, k);
        else if (point->key < k)
            return findV(point->right, k);
        else
            return 0;
    }

    void deleteTree(Node<T> *point) {
        if (point == nullptr)
            return;
        deleteTree(point->right);
        deleteTree(point->left);
        delete point;
        point = nullptr;
    }

 public:
    BST() : root(nullptr) {}

    void insert(T k) {
        root = insert(root, k);
    }

    int depth() {
        return Height(root) - 1;
    }

    int search(T k) {
        return findVal(root, k);
    }

    ~BST() {
        deleteTree(root);
    }
};
#endif  // INCLUDE_BST_H_
