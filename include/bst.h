// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {
 private:
    struct Node {
      T value;
      int number;
      Node *left; Node *right;
    };
    Node *root;
    Node *addNode(Node *root, const T& data) {
      if (root == nullptr) {
        root = new Node;
        root -> value = data;
        root -> number = 1;
        root -> left = root -> right = nullptr;
      } else if (data < root -> value) {
          root -> left = addNode(root -> left, data);
      } else if (data > root -> value) {
          root -> right = addNode(root -> right, data);
      } else {
        root -> number++;
      }
    return root;
    }

    int searchNode(Node *root, const T& data) {
      if (root == nullptr) {
        return 0;
      } else if (root -> value == data) {
        return root -> number;
      } else if (root -> value > data) {
        return searchNode(root -> left, data);
      } else {
        return searchNode(root -> right, data);
      }
    }

    int depthTree(Node *root) {
      int leftt = 0;
      int rightt = 0;
      if (root == nullptr) {
        return 0;
      } else {
        leftt = depthTree(root -> left);
        rightt = depthTree(root -> right);
        if (leftt > rightt) {
          return leftt+1;
        } else {
          return rightt+1;
        }
      }
    }

 public:
    BST() :root(nullptr) {}
    void addNode(const T& data) {
      root = addNode(root, data);
    }
    int depth() {
      return depthTree(root)-1;
    }
    int search(const T& data) {
      return searchNode(root, data);
    }
};


#endif  // INCLUDE_BST_H_
