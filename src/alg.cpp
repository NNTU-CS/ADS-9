// Copyright 2021 NNTU-CS
#include "bst.h"
#include <fstream>
#include <iostream>
#include <cctype>

BST<std::string> makeTree(const char *filename) {
    std::ifstream file(filename);
    std::string word;
    BST<std::string> binTree;

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return binTree;
    }

    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            word += std::tolower(ch);
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
