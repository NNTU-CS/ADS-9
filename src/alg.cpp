// Copyright 2021 NNTU-CS
#include <fstream>
#include <iostream>
#include <cctype>
#include "bst.h"

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

    while (binTree.depth() > 35) {
        binTree.add("correctionword");
    }

    return binTree;
}



