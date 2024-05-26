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
        return BST<std::string>();
    }
    BST<std::string> tree;
    std::string word;
    char c;
    while (file.get(c)) {
        if (isalpha(c)) {
            word += tolower(c);
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
