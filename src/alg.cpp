// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "File error!" << std::endl;
        return tree;
    }

    std::string word;
    char ch;

    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            word += std::tolower(static_cast<unsigned char>(ch));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }

    // Insert last word if the file ends with a letter
    if (!word.empty()) {
        tree.insert(word);
    }

    file.close();
    return tree;
}
