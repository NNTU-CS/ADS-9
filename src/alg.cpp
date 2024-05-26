// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string word;
    while (file >> std::noskipws word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        tree.add(word);
    }
    file.close();
    return tree;
}
