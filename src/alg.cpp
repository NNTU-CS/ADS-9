// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error!" << std::endl;
        exit(1);
    }

    char ch;
    std::string word;
    BST<std::string> tree;

    while (file.get(ch)) {
        if (isalpha(ch)) {
            word += tolower(ch);
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
