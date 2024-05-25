// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 public :
     struct Node {
          T value;
          int counter;
          Node* left;
          Node* right;
     };
     BST();
     void add(T value);
     void print();
     int deep();
     int search(T);

 private:
     Node* RootOfTree;
     Node* addNode(Node*, T);
     void printTree(Node*);
     int deepTree(Node*);
     int searchNode(Node*, T);
};

template <typename T>
BST <T>::BST() : RootOfTree(nullptr) {}

template <typename T>
typename BST <T>:: Node* BST <T>:: addNode(Node* RootOfTree, T value) {
    if (RootOfTree == nullptr) {
        RootOfTree = new Node;
        RootOfTree->value = value;
        RootOfTree->counter = 1;
        RootOfTree->left = RootOfTree->right = nullptr;
    } else if (RootOfTree->value > value) {
         RootOfTree->left = addNode(RootOfTree->left, value);
    } else if (RootOfTree->value < value) {
        RootOfTree->right = addNode(RootOfTree->right, value);
    } else {
        RootOfTree->count++;
        return  RootOfTree;
    }
}


template < typename T >
void BST <T>::add(T value) {
     RootOfTree = addNode(RootOfTree, value);
}

template < typename T >
void BST <T >:: printTree(Node*  RootOfTree) {
    if (RootOfTree == nullptr)
        return;
    printTree(RootOfTree->left);
    for (int i = 0; i <  RootOfTree->count ; i++)
        std :: cout <<  RootOfTree->value << "␣";
    printTree(RootOfTree->right);
}

template < typename T >
void BST <T>:: print() {
    printTree(RootOfTree);
}

template < typename T >
int BST <T>::deepTree(Node*  RootOfTree) {
    if (RootOfTree == nullptr) {
        return 0;
    } 
     if (leftDeep > rightDeep) {
        return leftDeep + 1;
    } else {
        return rightDeep + 1;
    }
}

template < typename T >
int BST <T >:: deep() {
    return deepTree(RootOfTree);
}

template<typename T>
int BST <T>:: Node * BST <T>:: searchNode(Node* RootOfTree, T value) {
    if (RootOfTree == nullptr) {
        return 0;
    } else {
        while (RootOfTree->value != value) {
            if ( RootOfTree->value > value ) {
                RootOfTree = RootOfTree->left;
            } else if (RootOfTree->value > value) {
                RootOfTree = RootOfTree->right;
            }
        }
        return deepTree(RootOfTree);
    }
}

template <typename T>
int BST <T>:: search(T value) {
     return searchNode(RootOfTree, value);
}

#endif  // INCLUDE_BST_H_
