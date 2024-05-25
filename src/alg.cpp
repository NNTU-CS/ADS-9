// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "File error!" << std::endl;
    }
    BST<std::string> tree;
    std::string word;
    char ch;
    while (file.get(ch)) {
        if (isalpha(ch)) {
            word += tolower(ch);
        } else if (!word.empty()) {
            tree.add(word);
            word.clear();
        }
    }
    return tree;
}
