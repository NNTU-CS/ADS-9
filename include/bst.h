// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_


template <typename T>
  class BST {
   public:
    struct Node {
      T value;
      Node* right;
      Node* left;
      int count;
    };

    BST() :root(nullptr) {}
    ~BST() {}
    void add(T value) {
      root = addNode(root, value);
    }
    int search(T value) {
      return searchNode(root, value);
    }
    int depth() {
      return depthTree(root) - 1;
    }

   private:
     Node* root;
     Node* addNode(Node* root, T value) {
      if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
      } else if (root->value < value) {
        root->right = addNode(root->right, value);
      } else if (root->value > value) {
        root->left = addNode(root->left, value);
      } else {
        root->count++;
      }
      return root;
    }

    int searchNode(Node* root, T value) {
      if (root == nullptr)
        return 0;
      else if (root->value < value)
        return searchNode(root->right, value);
      else if (root->value > value)
        return searchNode(root->left, value);
      else
        return root->count;
    }

    int depthTree(Node *root) {
        int leftHeight = 0, rightHeight = 0;
        if (root == nullptr) {
            return 0;
        } else {
            leftHeight = depthTree(root->left);
            rightHeight = depthTree(root->right);
        }
        if (rightHeight > leftHeight) {
            return rightHeight + 1;
        } else {
            return leftHeight + 1;
        }
    }
  };
#endif  // INCLUDE_BST_H_
