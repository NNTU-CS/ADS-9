// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node* left, * right;
        Node(const T& val) : value(val), count(1),
            left(nullptr), right(nullptr) {}
    };
    Node* root;
    Node* insert(Node* node, const T& value) {
        if (!node)
            return new Node(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else
            node->count++;
        return node;
    }
    int search(Node* node, const T& value) {
        return node ? (value < node->value ? search(node->left, value) :
            (value > node->value ? search(node->right, value)
                : node->count)) : 0;
    }
    int depth(Node* node) {
        return node ? 1 + std::max(depth(node->left),
            depth(node->right)) : 0;
    }

 public:
    BST() : root(nullptr) {}
    void add(const T& value) { root = insert(root, value); }
    int search(const T& value) { return search(root, value); }
    int depth() { return depth(root); }
};

#endif  // INCLUDE_BST_H_

