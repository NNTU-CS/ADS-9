// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
template <typename T>
class BST {
public:
    struct NodeData {
        T data;
        int count;
        NodeData* leftChild;
        NodeData* rightChild;
        NodeData(T value) : data(value), count(1), leftChild(nullptr), rightChild(nullptr) {}
    };
private:
    NodeData* rootNode;
    NodeData* insertNodeData(NodeData*, T);
    int calculateDepth(NodeData*);
    int findNodeData(NodeData*, T);
    void deleteNode(NodeData*);
public:
    BST() : rootNode(nullptr) {}
    ~BST() { deleteNode(rootNode); }
    void insert(T);
    int depth();
    int find(T);
};
template <typename T>
typename BST<T>::NodeData* BST<T>::insertNodeData(NodeData* node, T value) {
    if (node == nullptr) {
        node = new NodeData(value);
    } else if (node->data > value) {
        node->leftChild = insertNodeData(node->leftChild, value);
    } else if (node->data < value) {
        node->rightChild = insertNodeData(node->rightChild, value);
    } else {
        node->count++;
    }
    return node;
}
template <typename T>
void BST<T>::insert(T value) {
    rootNode = insertNodeData(rootNode, value);
}
template <typename T>
int BST<T>::calculateDepth(NodeData* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int leftDepth = calculateDepth(node->leftChild);
        int rightDepth = calculateDepth(node->rightChild);
        return std::max(leftDepth, rightDepth) + 1;
    }
}
template <typename T>
int BST<T>::depth() {
    return calculateDepth(rootNode);
}
template <typename T>
int BST<T>::findNodeData(NodeData* node, T val) {
    if (node == nullptr)
        return 0;
    else if (node->data == val)
        return node->count;
    else if (node->data > val)
        return findNodeData(node->leftChild, val);
    else
        return findNodeData(node->rightChild, val);
}
template <typename T>
int BST<T>::find(T v) {
    return findNodeData(rootNode, v);
}
template <typename T>
void BST<T>::deleteNode(NodeData* node) {
    if (node != nullptr) {
        deleteNode(node->leftChild);
        deleteNode(node->rightChild);
        delete node;
    }
}
BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    return tree;
}
#endif  // INCLUDE_BST_H_
