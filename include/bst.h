// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>

template <typename T>
  struct Node {
    Node<T>*prev = nullptr;
    Node<T>*left = nullptr;
    Node<T>*right = nullptr;
    int Count = 0;
    T value = "";
  };
template <typename T>
  class BST {
   private:
    Node<T>*root = nullptr;
    int height = 0;
    void printTree(Node<T>* tree, int id) {
      std::cout << id << " " << tree->value << std::endl;
      ++id;
      if (tree->left != nullptr) {
        printTree(tree->left, id);
      }
      if (tree->right != nullptr) {
        printTree(tree->right, id);
      }
    }
    void depthTree(Node<T>* tree, int id) {
      ++id;
      if (tree->right != nullptr) {
        depthTree(tree->right, id);
      }
      if (tree->left != nullptr) {
        depthTree(tree->left, id);
      }
      if (id > height) {
        height = id;
      }
    }
    void DelNode(Node<T>* Node) {
      if (Node->right != nullptr) {
        DelNode(Node->right);
      }
      if (Node->left != nullptr) {
        DelNode(Node->left);
      }
      delete Node;
    }

   public:
    BST() {
      root = nullptr;
      height = 0;
    }
    ~BST() {
      DelNode(root);
    }
    int search(T item) {
      Node<T>* current = root;
      while (true) {
        if (current == nullptr) {
          throw std::string("Tree is Empty!");
        } else if (current->value < item) {
          current = current->right;
        } else if (current->value == item) {
          return current->Count;
        } else {
          current = current->left;
        }
      }
    }
    void Add(T item) {
      Node<T>* current = root;
      Node<T>* prev = nullptr;
      int pos = 0;
      while (true) {
        if (current == nullptr) {
          current = new Node<T>;
          current->value = item;
          current->right = nullptr;
          current->left = nullptr;
          current->Count = 1;
          if (prev != nullptr) {
            current->prev = prev;
            if (pos == 1) {
              prev->right = current;
            } else {
              prev->left = current;
            }
            prev = nullptr;
            pos = 0;
            }
          if (root == nullptr) {
            root = current;
          }
          break;
        }
        if (current->value < item) {
          prev = current;
          pos = 1;
          current = current->right;
        } else if (current->value == item) {
          current->Count++;
          break;
        } else {
          pos = -1;
          prev = current;
          current = current->left;
        }
      }
    }
    void Print() {
      Node<T>* current = root;
      printTree(current, 0);
    }
    int depth() {
      Node<T>* current = root;
      depthTree(current, 0);
      return height - 1;
    }
  };
#endif  // INCLUDE_BST_H_
