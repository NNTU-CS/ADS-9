// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string word1;
    while (!file.eof()) {
        char ch = file.get();
        if (ch != ' ' && isalpha(ch)) {
            ch = tolower(ch);
            word1 += ch;
        } else {
            tree.insert(word1);
            word1.clear();
        }
    }
    return tree;
}
