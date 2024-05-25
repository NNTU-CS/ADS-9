// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include <sstream>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Ошибка открытия файла");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string word;
        for (char c : line) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            tree.insert(word);
        }
    }

    file.close();
    return tree;
}
