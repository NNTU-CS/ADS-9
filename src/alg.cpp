// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    std::string word;
    BST<std::string> tree;

    while (!file.eof()) {
        char c = file.get();

        if (std::isalpha(c)) {
            word += c;
        } else if (word.length() != 0) {
            tree.insert(word);
            word = "";
        }
    }
    return tree;
}
