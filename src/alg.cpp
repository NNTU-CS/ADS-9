// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

std::string lower(std::string s) {
    for (auto & x : s) {
        x = tolower(x);
    }
    return s;
}

BST<std::string> makeTree(const char *filename) {
    BST<std::string> binTree;
    std::ifstream fin(filename);
    std::string w = "";
    while (!fin.eof()) {
        char c = fin.get();
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            w += c;
        } else {
            w = lower(w);
            binTree.add(w);
            w = "";
        }
    }
    return binTree;
}
