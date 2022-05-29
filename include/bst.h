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
    Node* koren;
    Node* addNode(Node, T);
    int depthTree(Node);
    int searchNode(Node, T);
};

template <typename T>
BST<T>::BST(): koren(nullptr) {}

template <typename T>
typename BST<T>::Node BST<T>::addNode(Node* koren, T value) {
    if (koren == nullptr) {
        koren = new Node;
        koren->value = value;
        koren->count = 1;
        koren->lt = koren->rt = nullptr;
    } else if (koren->value > value) {
        koren->lt = addNode(koren->lt, value);
    } else if (koren->value < value) {
        koren->rt = addNode(koren->rt, value);
    } else {
        koren->count++;
    }
    return koren;
}

template <typename T>
int BST<T>::depthTree(Node* koren) {
    if (koren == nullptr) {
        return 0;
    } else {
        int left, right;
        left = depthTree(koren->lt);
        right = depthTree(koren->rt);
        if (right > left) {
            return right + 1;
        } else {
            return left + 1;
        }
    }
}

template <typename T>
int BST<T>::searchNode(Node* koren, T val) {
    if (koren == nullptr) {
        return 0;
    } else if (koren->value == val) {
        return koren->count;
    } else if (koren->value > val) {
        return searchNode(koren->lt, val);
    } else {
        return searchNode(koren->rt, val);
    }
}

template <typename T>
void BST<T>::add(T value) {
    koren = addNode(koren, value);
}

template <typename T>
int BST<T>::depth() {
    return depthTree(koren) - 1;
}

template <typename T>
int BST<T>::search(T value) {
    return searchNode(koren, value);
}

#endif  // INCLUDE_BST_H_
