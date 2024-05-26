// Copyright 2021 NNTU-CS
#include <fstream>
#include <iostream>
#include <cctype>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "gg" << std::endl;
        return BST<std::string>();
    }
    char ch;
    std::string word;
    BST<std::string> binTree;
    while (file.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += std::tolower(static_cast<unsigned char>(ch));
        } else if (!word.empty()) {
            binTree.add(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        binTree.add(word);
    }
    file.close();
    return binTree;
}