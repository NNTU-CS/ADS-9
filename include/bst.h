// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count = 0;
        Node* lf;
        Node* rt;
    };
    BST();
    void add(T);
    int depth();
    int search(T);
 private:
    Node* root;
    Node* addNode(Node, T);
    int depthTree(Node);
    int searchNode(Node, T);
};

template <typename T>
BST<T>::BST(): root(nullptr) {}

template <typename T>
typename BST<T>::Node BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->lt = root->rt = nullptr;
    } else if (root->value > value) {
        root->lt = addNode(root->lt, value);
    } else if (root->value < value) {
        root->rt = addNode(root->rt, value);
    } else {
        root->count++;
    }
    return root;
}

template <typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int left, right;
        left = depthTree(root->lt);
        right = depthTree(root->rt);
        if (right > left) {
            return right + 1;
        } else {
            return left + 1;
        }
    }
}

template <typename T>
int BST<T>::searchNode(Node* root, T val) {
    if (root == nullptr) {
        return 0;
    } else if (root->value == val) {
        return root->count;
    } else if (root->value > val) {
        return searchNode(root->lt, val);
    } else {
        return searchNode(root->rt, val);
    }
}

template <typename T>
void BST<T>::add(T value) {
    root = addNode(root, value);
}

template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}

template <typename T>
int BST<T>::search(T value) {
    return searchNode(root, value);
}

#endif  // INCLUDE_BST_H_
