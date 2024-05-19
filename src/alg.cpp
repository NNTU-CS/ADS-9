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
        std::cerr << "File error!" << std::endl;
        return tree;
    }
    std::string word;
    while (file) {
        char ch = file.get();
        if (std::isalpha(ch)) {
            word += std::tolower(ch);
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
