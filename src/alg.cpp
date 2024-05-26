// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file: " << filename << std::endl;
        return tree;
    }
    std::string word;
    while (file >> word) {
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
            return std::tolower(c);
        });
        tree.add(word);
    }
    file.close();
    return tree;
}
