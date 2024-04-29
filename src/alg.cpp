// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return BST<std::string>();
    }

    BST<std::string> tree;
    std::string word;
    char ch;

    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            ch = std::tolower(ch);
            word += ch;
        } else if (!word.empty()) {
            tree.insert(word);
            word.clear();
        }
    }

    if (!word empty()) {
        tree.insert(word);
    }

    file.close();
    return tree;
}
