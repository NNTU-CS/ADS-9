// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isAlpha(char ch) {
    return std::isalpha(static_cast<unsigned char>(ch));
}

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Error File !" << std::endl;
        return tree;
    }

    std::string word;
    while (!file.eof()) {
        char ch = file.get();
        if (file.eof()) break;

        if (isAlpha(ch)) {
            word += std::tolower(static_cast<unsigned char>(ch));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        tree.insert(word);
    }

    file.close();
    return tree;
}
