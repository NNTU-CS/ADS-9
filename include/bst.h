// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>

template <typename T>
class BST {
public:
    struct Node {
        T data;
        int count;
        Node* left;
        Node* right;

        Node(const T& data) : data(data), count(1), left(nullptr), right(nullptr) {}
    };

    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void insert(const T& data);
    int find(const T& data) const;
    void clear(Node* node);

private:
    Node* root;
};
#endif  // INCLUDE_BST_H_
