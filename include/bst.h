// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <iostream>

template <typename T>
class BST {
private:
   
    struct Node {
        T data;        
        int count;      
        Node *left;     
        Node *right;    

      
        Node(T val) : data(val), count(1), left(nullptr), right(nullptr) {}
    };

    Node *root; // Корень дерева

    void insert(Node *&node, const T &val) {
        if (!node) {
            node = new Node(val);
        } else if (val < node->data) {
            insert(node->left, val);
        } else if (val > node->data) {
            insert(node->right, val);
        } else {
            node->count++;
        }
    }

    void inOrder(Node *node) const {
        if (node) {
            inOrder(node->left);
            std::cout << node->data << " - " << node->count << std::endl;
            inOrder(node->right);
        }
    }

public:
    // Конструктор дерева
    BST() : root(nullptr) {}

    void insert(const T &val) {
        insert(root, val);
    }

    void inOrder() const {
        inOrder(root);
    }
};

#endif  // INCLUDE_BST_H_
