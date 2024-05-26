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
    }
    std::string word;
    char symb;
    BST<std::string> tree;
    while (file.get(symb)) {
        if (isalpha(symb)) {
            word += tolower(symb);
        } else {
            three.add(word);
            word.clear();
        }
    }
    file.close();
    return tree;
}
