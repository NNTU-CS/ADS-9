// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_


template<typename T>
  class BST{
   public:
     struct NodeT {
       int counter;
       T value;
       NodeT *left;
       NodeT *right;
     };

   private:
     NodeT* root;
     NodeT* AddNodeT(NodeT* root, T date) {
         if (root == nullptr) {
           root = new NodeT;
           root->counter = 1;
           root->value = date;
           root->right = nullptr;
           root->left = nullptr;
         } else {
           if (date < root->value) root->left = AddNodeT(root->left, date);
           else if (date > root->value) root->right = AddNodeT(root->right, date);
           else
               root->counter++;
           }
         return root;
    }
    int SearchNodeT(NodeT* root, T date) {
      if (root == nullptr) {
          return 0;
      } else if (root->value == date) {
          return root->counter;
      } else if (root->value > date) {
          return SearchNodeT(root->left, date);
      } else {
          return SearchNodeT(root->right, date);
      }
    }
    int HeightTreeT(NodeT* root) {
        if (root == nullptr) {
          return 0;
        } else {
            int left = HeightTreeT(root->left);
            int right = HeightTreeT(root->right);
            if (right < left) {
                return ++left;
            } else {
                return ++right;
            }
        }
    }

   public:
      BST() {
         root = nullptr;
     }
     void Add_NodeT(T date) {
         root = AddNodeT(root, date);
     }
     int depth() {
         return HeightTreeT(root) - 1;
     }
     int search(T date) {
        return SearchNodeT(root, date);
     }
  };
#endif  // INCLUDE_BST_H_
