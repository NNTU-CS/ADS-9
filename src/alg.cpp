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
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string word;
    while (file >> word) {
        for (char& c : word) {
            c = std::tolower(c);
        }
        tree.insert(word);
    }
    file.close();
    return tree;
}
