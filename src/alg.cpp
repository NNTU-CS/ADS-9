// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file.good()) {
        std::cerr << "Ошибка при открытии файла: " << filename << std::endl;
        return tree;
    }

    std::string word;
    char ch;
    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            word += std::tolower(ch);
        } else {
            if (!word.empty()) {
                tree.add(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tree.add(word);
    }
    file.close();
    return tree;
}
