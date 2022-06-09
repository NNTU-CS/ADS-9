// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
    struct Node {
        int count;
        T value;
        Node* left;
        Node* right;
    };

    Node* first;

    Node* createNode(Node* first, T _value) {
        if (first == nullptr) {
            first = new Node;
            first->count = 1;
            first->value = _value;
            first->left = nullptr;
            first->right = nullptr;
        } else if (first->value < _value) {
            first->right = createNode(first->right, _value);
        } else if (first->value > _value) {
            first->left = createNode(first->left, _value);
        } else {
            first->count++;
        }
        return first;
    }

    int depth(Node* first) {
        if (first == nullptr || (first->left == nullptr && first->right == nullptr)) {
            return 0;
        }
        int left = depth(first->left);
        int right = depth(first->right);
        if (left > right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }

    int search(Node* first, T _value) {
        Node* t = first;
        if (first == nullptr) {
            return 0;
        } else {
            if (first->value == _value) {
                return first->count;
            } else if (first->value < _value) {
                return search(first->right, _value);
            } else {
                return search(first->left, _value);
            }
        }
    }

 public:
    BST() {
        first = nullptr;
    }

    void add(T _value) {
        first = createNode(first, _value);
    }

    int depth() {
        return depth(first);
    }

    int search(T _value) {
        return search(first, _value);
    }
};
#endif  // INCLUDE_BST_H_
