// Copyright 2021 NNTU-CS
#include "alg.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "File error!" << std::endl;
        return BST<std::string>();
    }

    BST<std::string> tree;
    std::string word;
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            word += std::tolower(ch);
        } else if (!word.empty()) {
            tree.insert(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        tree.insert(word);
    }
    file.close();
    return tree;
}

