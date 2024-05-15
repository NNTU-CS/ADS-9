// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        exit(1);
    }
    char symbol;
    std::string speech;
    BST<std::string> tree;
    while (file.get(symbol)) {
        if (isalpha(symbol)) {
            speech += tolower(symbol);
        } else if (!speech.empty()) {
            tree.insert(speech);
            speech.clear();
        }
    }
    file.close();
    return tree;
}
