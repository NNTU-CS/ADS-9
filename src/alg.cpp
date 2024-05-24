// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::string word;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::string("Error");
    }

    while (file) {
        char letter = file.get();
        if (isalpha(letter)) {
            letter = tolower(letter);
            word += letter;
        } else if (!word.empty()) {
            tree.add(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        tree.add(word);
    }

    file.close();
    return tree;
}
