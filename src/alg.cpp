// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isAlpha(char c) {
    return std::isalpha(c);
}

bool isEmpty(const std::string &word) {
    return word.empty();
}

std::string toLower(char c) {
    return std::string(1, std::tolower(c));
}

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string word;

    while (!file.eof()) {
        char c = file.get();
        if (isAlpha(c)) {
            word += toLower(c);
        } else if (!isEmpty(word)) {
            tree.insert(word);
            word = "";
        }
    }

    if (!isEmpty(word)) {
        tree.insert(word);
    }

    return tree;
}
