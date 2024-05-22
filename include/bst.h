// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>
class BST {
 private :
    struct Node {
        T value;
        int count;
        Node *l;
        Node *r;
    };

    Node *root;

    Node *addNode(Node *root, T v) {
        if (!root) {
            root = new Node;
            root->value = v;
            root->l = root->r = nullptr;
        } else if (root->value > v) {
            root->l = addNode(root->l, v);
        } else if (root->value < v) {
            root->r = addNode(root->r, v);
        } else {
            (root->count)++;
        }
        return root;
    }

    int searchValue(Node *root, T v) {
        if (!root) {
            return 0;
        } else if (root->value == v) {
            return root->count;
        } else if (root->value > v) {
            return searchValue(root->l, v);
        } else {
            return searchValue(root->r, v);
        }
    }

    int heightTree(Node *root) {
        if (!root) {
            return 0;
        }
        int L = heightTree(root->l);
        int R = heightTree(root->r);
        if (L > R) {
            return (L + 1);
        } else {
            return (R + 1);
        }
    }

 public :
    BST() : root(nullptr) {
    }

    void add(T v) {
        root = addNode(root, v);
    }

    int search(T v) {
        return searchValue(root, v) + 1;
    }

    int depth() {
        return heightTree(root) - 1;
    }
};
#endif  // INCLUDE_BST_H_
