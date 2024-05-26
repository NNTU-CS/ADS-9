// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <class T>
class BST {
 private:
    struct BTNode {
        T value;
        int count;
        BTNode* left;
        BTNode* right;
        explicit BTNode(T data) : value(data), count(1) {
            left = nullptr;
            right = nullptr;
        }
    };

    BTNode* root;
    BTNode* addBST(BTNode*, T);
    int depthBST(BTNode*);

 public:
    BST();
    void add(T);
    int depth();
    int search(T);
};

template <class T> BST<T>::BST() : root(nullptr) {}
template <class T>
typename BST<T>::BTNode* BST<T>::addBST(BTNode* node, T value) {
    if (node == nullptr)
        node = new BTNode(value);
    else if (node->value < value)
        node->right = addBST(node->right, value);
    else if (node->value > value)
        node->left = addBST(node->left, value);
    else
        node->count++;
    return node;
}

template <class T>
void BST<T>::add(T value) {
    root = addBST(root, value);
}

template <class T>
int BST<T>::depthBST(BTNode* node) {
    if (node == nullptr)
        return -1;
    int right = depthBST(node->right);
    int left = depthBST(node->left);
    return 1 + (left > right ? left : right);
}

template <class T>
int BST<T>::depth() {
    return depthBST(root);
}

template <class T>
int BST<T>::search(T value) {
    if (root == nullptr) {
        return 0;
    }
    BTNode* node = root;
    while (true) {
        if (node->value > value)
            node = node->left;
        else if (node->value < value)
            node = node->right;
        else
            return node->count;
    }
}
#endif  // INCLUDE_BST_H_
