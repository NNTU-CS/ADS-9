// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {

public:
    struct Node {
        T znach;
        int pov;
        Node* l;
        Node* r;
    };

private:
    Node* hed;
    Node* a_n(Node*, T);
    int d_t(Node*, int);
    int s_n(Node*, T);
    void delTree(Node*);

public:
    BST();
    ~BST();
    void add(T);
    int search(T);
    int depth();
    void clear();
};

template <typename T>
BST <T>::BST() : hed(nullptr) {}
template <typename T>
BST <T>::~BST() {
    if (hed)
        delTree(hed);
}
template <typename T>
void BST <T>::add(T zn) {
    hed = a_n(hed, zn);
}
template <typename T>
typename BST <T>::Node* BST <T>::a_n(Node* hed, T zn) {
    if (hed == nullptr) {
        hed = new Node;
        hed->znach = zn;
        hed->pov = 1;
        hed->l = hed->r = nullptr;
    } else if (hed->znach > zn) {
        hed->l = a_n(hed->l, zn);
    } else if (hed->znach < zn) {
        hed->r = a_n(hed->r, zn);
    } else {
        hed->pov++;
    }
    return hed;
}


template <typename T>
void BST <T>::delTree(Node* hed) {
    if (hed == nullptr) {
        return;
    } else {
        delTree(hed->l);
        delTree(hed->r);
        delete hed;
    }
}
template <typename T>
void BST <T>::clear() {
    if (hed) {
        delTree(hed);
        hed = nullptr;
    }
}

template <typename T>
int BST <T>::search(T str) {
    return s_n(hed, str);
}

template <typename T>
int BST <T>::s_n(Node* hed, T str) {
    if (hed == nullptr)
        return 0;
    else if (hed->znach == str)
        return hed->pov;
    else if (hed->znach > str)
        return s_n(hed->l, str);
    else
        return s_n(hed->r, str);
}

template <typename T>
int BST <T>::depth() {
    if (hed) {
        return d_t(hed, 1);
    }
    return 0;
}

template <typename T>
int BST <T>::d_t(Node* hed, int qg) {
    if (hed == NULL)
        return qg - 1;
    return std::max(d_t(hed->l, qg + 1), d_t(hed->r, qg + 1));
}
#endif  // INCLUDE_BST_H_
