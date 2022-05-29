// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>

template <typename T>
struct Node {
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
    int count = 0;
    T value = "";
};
template <typename T>
class BST {
 private:
    Node<T> *root;
    int depthValue;
    void getDepth(Node<T>*tree, int index) {
        ++index;
        if (tree->left != nullptr) {
            getDepth(tree->left, index);
        }
        if (tree->right != nullptr) {
            getDepth(tree->right, index);
        }
        index > depthValue ? depthValue = index : depthValue;
    }

 public:
    BST() {
        root = nullptr;
        depthValue = 0;
    }
    void Add(T element) {
        Node<T>* current = root;
        if (current == nullptr) {
            current = new Node<T>;
            current->left = nullptr;
            current->right = nullptr;
            current->value = element;
            current->count = 1;
            root = current;
            return;
        } else {
            Node<T>* pref = nullptr;
                bool isleft = false;
            while (true) {
               if (current == nullptr) {
                    current = new Node<T>;
                    current->left = nullptr;
                    current->right = nullptr;
                    current->value = element;
                    current->count = 1;
                    if (pref != nullptr) {
                        if (isleft == true) {
                            pref->left = current;
                        } else {
                            pref->right = current;
                        }
                        pref = nullptr;
                    }
                    break;
                } else if (element == current->value) {
                    current->count++;
                    break;
                } else if (element > current->value) {
                    isleft = false;
                    pref = current;
                    current = current->right;
                } else if (element < current->value) {
                    isleft = true;
                    pref = current;
                    current = current->left;
                }
            }
        }
    }
    int search(T element) {
        Node<T>* current = root;
        while (true) {
            if (current->value == element) {
                return current->count;
            } else if (element > current->value) {
                current = current->right;
            } else if (element < current->value) {
                current = current->left;
            }
        }
    }
    int depth() {
        Node<T>* current = root;
        getDepth(current, 0);
        return depthValue - 1;
    }
};

#endif  // INCLUDE_BST_H_
