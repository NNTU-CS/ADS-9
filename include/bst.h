// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
     struct Node {
         T value;
         int count;
         Node* left;
         Node* right;
     };

Node* root;
Node* addNode(Node* root, const T& val) {
    if (root == nullptr) {
        root = new Node;
        root->value = val;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (val > root->value) {
        root->left = addNode(root->left, val);
    } else if (val < root->value) {
        root->right = addNode(root->right, val);
    } else {
        root->count++;
    }
    return root;
}

int searchNode(Node* root, const T& val) {
    if (root == nullptr) {
        return 0;
    } else if (root->value == val) {
        return root->count;
    } else if (root->value < val) {
        return searchNode(root->left, val);
    } else {
        return searchNode(root->right, val);
    }
}
int depthTree(Node* root) {
    int L = 0, R = 0;
    if (root == nullptr) {
        return 0;
    } else {
        L = depthTree(root->left);
        R = depthTree(root->right);
    }
    if (L > R) {
        return L + 1;
    } else {
        return R + 1;
    }
}

 public:
    BST() :root(nullptr) {}
void add(const T& val) {
    root = addNode(root, val);
}
int search(const T& val) {
    return searchNode(root, val);
}
int depth() {
    return depthTree(root)- 1;
}
};
#endif  // INCLUDE_BST_H_
