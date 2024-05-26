// Copyright 2021 NNTU-CS
#include <fstream>
#include <sstream>
#include <string>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;

    if (!file.is_open()) {
        std::cerr << "File error!" << std::endl;
        return tree;
    }

    std::string word;
    while (file >> word) {
        tree.insert(word);
    }

    file.close();
    return tree;
}
