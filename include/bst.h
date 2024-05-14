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
    };
private:
    NodeData* rootNode;
    NodeData* insertNodeData(NodeData*, T);
    int calculateDepth(NodeData*);
    int findNodeData(NodeData*, T);
public:
    BST();
    void insert(T);
    int depth();
    int find(T);
};
template <typename T>
BST <T>::BST() : rootNode(nullptr) {}
template <typename T>
typename BST <T>::NodeData* BST <T>::insertNodeData(NodeData* node, T value) {
    if (node == nullptr) {
        node = new NodeData;
        node->data = value;
        node->count = 1;
        node->leftChild = node->rightChild = nullptr;
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
void BST <T>::insert(T value) {
    rootNode = insertNodeData(rootNode, value);
}
template <typename T>
int BST<T>::calculateDepth(NodeData* node) {
    if (node == nullptr) {
        return 0;
    } else {
        int leftDepth = calculateDepth(node->leftChild);
        int rightDepth = calculateDepth(node->rightChild);
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
}
template <typename T>
int BST<T>::depth() {
    return calculateDepth(rootNode) - 1;
}
BST<std::string> makeTree(const char* filename);
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
#endif  // INCLUDE_BST_H_
