// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 private:
    struct Node {
      T value;
      int count;
      Node *left;
      Node *right;
    };
    Node *root;
    Node *addNode(Node *root, const T& information) {
      if (root == nullptr) {
        root = new Node;
        root -> value = information;
        root -> count = 1;
        root -> left = root -> right = nullptr;
      } else if (information < root -> value) {
          root -> left = addNode(root -> left, information);
      } else if (information > root -> value) {
          root -> right = addNode(root -> right, information);
      } else {
        root -> count++;
      }
    return root;
    }

    int searchNode(Node *root, const T& information) {
      if (root == nullptr) {
        return 0;
      } else if (root -> value == information) {
        return root -> count;
      } else if (root -> value > information) {
        return searchNode(root -> left, information);
      } else {
        return searchNode(root -> right, information);
      }
    }

    int depthTree(Node *root) {
      int leftct = 0, rightct = 0;
      if (root == nullptr) {
        return 0;
      } else {
        leftct = depthTree(root -> left);
        rightct = depthTree(root -> right);
        if (leftct > rightct) {
          return ++leftct;
        } else {
          return ++rightct;
        }
      }
    }

 public:
    BST() :root(nullptr) {}
    void addNode(const T& information) {
      root = addNode(root, information);
    }
    int depth() {
      return depthTree(root)-1;
    }
    int search(const T& information) {
      return searchNode(root, information);
    }
};

#endif  // INCLUDE_BST_H_
//Made by AndySter
