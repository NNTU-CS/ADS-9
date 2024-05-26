// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string word;
    while (!file.eof()) {
        char str = file.get();
        if (str >= 'a' && str <= 'z') {
            word += str;
        }
        if (str >= 'A' && str <= 'Z') {
            str = tolower(str);
        } else {
            tree.add(word);
            word.clear();
        }
    }
    return tree;
}
