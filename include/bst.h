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
      int counter1;
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
        root->counter1 = 1;
        root->left = root->right = nullptr;
      } else if (root->value < value) {
        root->right = addNode(root->right, value);
      } else if (root->value > value) {
        root->left = addNode(root->left, value);
      } else {
        root->counter1++;
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
        return root->counter1;
    }

    int depthTree(Node *root) {
        int lefth = 0, righth = 0;
        if (root == nullptr) {
            return 0;
        } else {
            lefth = depthTree(root->left);
            righth = depthTree(root->right);
        }
        if (righth > lefth) {
            return rightHeight + 1;
        } else {
            return lefth + 1;
        }
    }
  };
#endif  // INCLUDE_BST_H_
